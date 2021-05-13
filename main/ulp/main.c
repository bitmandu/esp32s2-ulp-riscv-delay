/**
 * @file main.c
 */

#include "ulp_riscv/ulp_riscv.h"
#include "ulp_riscv/ulp_riscv_utils.h"

#include "soc/rtc_io_reg.h"

volatile int pin;

extern void wait(int);

// C implementation about 2x slower
// void wait_c(volatile int n)
//{
//    do {
//	;
//    } while (--n);
//}

int main(void)
{
    while (1) {
        REG_SET_FIELD(RTC_GPIO_OUT_W1TS_REG, RTC_GPIO_OUT_DATA_W1TS, 1 << pin);
        wait(1000);

        REG_SET_FIELD(RTC_GPIO_OUT_W1TC_REG, RTC_GPIO_OUT_DATA_W1TC, 1 << pin);
        wait(1000);
    }
}
