#include "../include/utfc.h"
#include <errno.h>
#include <stdio.h>

void hello(void) {
  printf("Hello, World!\n");
}

utf8_char *ParseRawBytes(byte *bytes, size_t size) {
  for (int _ = 0; _ < size; _++) {

  }
}

utf8_char *EncodeAscii(const char *string, size_t size) {
  int mask = 0b10000000;
  byte bytes[size];
  utf8_char *utf8Char = malloc(sizeof(utf8Char)*size);
  if (utf8Char == NULL) {
    errno = ENOMEM;
    return NULL;
  }

  for (int _ = 0; _ < size; _++) {
    bytes[_] = (byte) (string[_] | mask);
  }

  for (int _ = 0; _ < size; _++) {

  }
}
