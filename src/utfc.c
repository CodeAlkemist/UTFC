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

utf8_char EncodeAsciiChar(char char_) {
  int mask = 0b01111111;
  byte bytes[4] = {0, 0, 0, 0};
  bytes[0] = (byte) (char_ & mask);
}

utf8_char *EncodeAscii(const char *string, size_t size) {
  utf8_char *utf8Char = malloc(sizeof(utf8Char)*size);
  if (utf8Char==NULL) {
    errno = ENOMEM;
    return NULL;
  }

  for (int _ = 0; _ < size; _++) {
    utf8Char[_] = EncodeAsciiChar(string[_]);;
  }

  return utf8Char;
}

int IsCharEqual(utf8_char left, utf8_char right) {
  for (int _ = 0; _ < 4; _++) {
    if (left.bytes[_]==right.bytes[_]) {
      return 0;
    }
  }
  return 1;
}

int ValidateSector(byte sect) {
  if ((0b10000000 & sect) != 0 && (0b01000000 & sect) == 0)
    return 1;
  else
    return 0;
}

int ValidateChar(utf8_char char_) {
  short s1 = 0b1000;
  short s2 = 0b0100;
  short s3 = 0b0010;
  short s4 = 0b0001;
  short bp = 0b1111;
  if ((0b10000000 & char_.bytes[0]) != 0)
    bp |= s1;
  else if ((0b00100000 & char_.bytes[0]) != 0)
    bp = ValidateSector(char_.bytes[1]) ? bp | s2 : bp;

}

size_t UtfStrlen(utf8_char *str) {
  size_t size = 0;
  while (ValidateChar(str[size])) {
    size++;
  }
}
