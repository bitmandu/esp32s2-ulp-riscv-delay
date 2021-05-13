# esp32s2-ulp-riscv-delay

This is an ESP-IDF example application exploring the clock frequency
of the [ESP32-S2 ULP-RISC-V coprocessor][1]

This code relates to a [help request I posted on the esp32.com forum][2].

## Installation

	$ git clone https://github.com/bitmandu/esp32s2-ulp-riscv-delay.git

## Configuration

        $ idf.py set-target esp32s2
        $ idf.py menuconfig

In the `Component config` ⇨ `ESP32S2-specific` menu check:

- [x] Enable Ultra Low Power (ULP) Coprocessor
- [x] Enable RISC-V as ULP coprocessor

## Contributing

[Pull requests][pulls] and [issue/bug reports][issues] are very much
encouraged!

## License

[MIT](LICENSE)


[1]: https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-guides/ulp-risc-v.html
[2]: https://esp32.com/viewtopic.php?f=2&t=20919
[issues]: https://github.com/bitmandu/esp32s2-ulp-riscv-delay/issues
[pulls]: https://github.com/bitmandu/esp32s2-ulp-riscv-delay/pulls
