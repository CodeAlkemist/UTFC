cmake_minimum_required(VERSION 3.13)
project(UTFC VERSION 1.0.0  LANGUAGES C)

set(CMAKE_C_STANDARD 99)

add_library(utfc src/utfc.c include/utfc.h)
add_library(utfcs SHARED src/utfc.c include/utfc.h)
configure_file(utfc.pc.in utfc.pc @ONLY)
add_executable(utfctest test/test.c)
include_directories(utfctest include)
target_link_libraries(utfctest utfc)