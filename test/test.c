// This file is dedicated by the copyright holder to the public domain WITHOUT ANY WARRANTY IN ANY WAY SHAPE OR FORM

#include <utfc.h>
#include <memory.h>
#include <stdio.h>
#define DEBUG
void main() {
  const char *helloascii = "Hello utf-8";
  utf8_char *encoded = EncodeAscii(helloascii, strlen(helloascii));

  printf("#""BYTE_TO_BINARY_PATTERN""\n", BYTE_TO_BINARY_PATTERN());
}