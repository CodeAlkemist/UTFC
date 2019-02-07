cmake_minimum_required(VERSION 3.13)
project(UTFC VERSION 1.0.0  LANGUAGES C)

set(CMAKE_C_STANDARD 99)

add_library(utfc src/utfc.c include/utfc.h)
add_library(utfcd SHARED src/utfc.c include/utfc.h)
configure_file(utfc.pc.in utfc.pc @ONLY)