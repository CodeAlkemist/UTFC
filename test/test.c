// This file is dedicated by the copyright holder to the public domain WITHOUT ANY WARRANTY IN ANY WAY SHAPE OR FORM

#include <utfc.h>
#include <memory.h>
#include <stdio.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

void main() {
  const char *helloascii = "Hello utf-8";
  utf8_char *encoded = EncodeAscii(helloascii, strlen(helloascii));
  for (int _ = 0; _ < strlen(helloascii); _++) {
    printf("bytes of char %i", _);
    printf(" > "BYTE_TO_BINARY_PATTERN"-"BYTE_TO_BINARY_PATTERN"-"BYTE_TO_BINARY_PATTERN"-"BYTE_TO_BINARY_PATTERN,
           BYTE_TO_BINARY(encoded[_].bytes[0]),
           BYTE_TO_BINARY(encoded[_].bytes[1]),
           BYTE_TO_BINARY(encoded[_].bytes[2]),
           BYTE_TO_BINARY(encoded[_].bytes[3]));
    printf(" > %c \n", encoded[_].bytes[0]);
  }
  FILE *fh = fopen("test.txt", "w+b");
  for (int _ = 0; _ < UtfStrlen(encoded); _++) {
    fwrite(&encoded[_].bytes[0], sizeof(byte), 1, fh);
  }
  fclose(fh);
}