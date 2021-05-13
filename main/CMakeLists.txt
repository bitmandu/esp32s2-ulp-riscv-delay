# CMakeLists.txt

idf_component_register(SRCS "esp32s2-ulp-riscv-delay.c"
  INCLUDE_DIRS "."
  PRIV_REQUIRES ulp riscv)

set(ulp_app_name ulp_${COMPONENT_NAME})
set(ulp_srcs "ulp/wait.S" "ulp/main.c")
set(ulp_dep_srcs "esp32s2-ulp-riscv-delay.c")

ulp_embed_binary(${ulp_app_name} "${ulp_srcs}" "${ulp_dep_srcs}")
