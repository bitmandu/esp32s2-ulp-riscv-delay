/**
 * @file esp32s2-ulp-riscv-delay.c
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/rtc_io.h"
#include "esp32s2/ulp_riscv.h"
#include "esp_log.h"
#include "esp_sleep.h"

#include "soc/rtc.h"

#include "ulp_main.h"

static const char *TAG = "esp32s2-ulp-riscv-delay";

extern const uint8_t bin_start[] asm("_binary_ulp_main_bin_start");
extern const uint8_t bin_end[] asm("_binary_ulp_main_bin_end");

static void delay_ulp_init(gpio_num_t gpio_num)
{
    ESP_ERROR_CHECK(ulp_riscv_load_binary(bin_start, bin_end - bin_start));

    /* initialize ULP RTC GPIO */
    ulp_pin = rtc_io_number_get(gpio_num);
    ESP_LOGI(TAG, "GPIO_NUM %d => RTC GPIO_NUM %d", gpio_num, ulp_pin);
    rtc_gpio_init(ulp_pin);
    rtc_gpio_set_direction(ulp_pin, RTC_GPIO_MODE_OUTPUT_ONLY);

    ulp_set_wakeup_period(0, 20000);
    ESP_ERROR_CHECK(ulp_riscv_run());
}

void app_main(void)
{
    uint32_t period;
    esp_sleep_wakeup_cause_t cause = esp_sleep_get_wakeup_cause();

    if (cause != ESP_SLEEP_WAKEUP_TIMER) {
        delay_ulp_init(CONFIG_GPIO_NUM);
    }

    period = rtc_clk_cal(RTC_CAL_RTC_MUX, 100);
    ESP_LOGI(TAG, "RTC_CAL_RTC_MUX clock period = %d", period);

    period = rtc_clk_cal(RTC_CAL_8MD256, 100);
    ESP_LOGI(TAG, "RTC_CAL_8MD256 clock period = %d", period);
}
