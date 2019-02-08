/// @copyright (c) 2019 Delta Foundry All Rights Reserved.

#ifndef UTFC_LIBRARY_H
#define UTFC_LIBRARY_H

#include <stdlib.h>

/**
 *
 */
typedef unsigned char byte;

/**
 *
 */
typedef struct __utf8_codepoint__ {
  byte bytes[4];
} utf8_char;

/**
 * Parse a raw arbitrary amount of bytes into a utf-8 string.
 * @param bytes
 * @param size
 * @return A utf8_string corresponding to the characters identified in the bytes passed
 */
extern utf8_char *ParseRawBytes(byte *bytes, size_t size);

/**
 *
 * @param string
 * @param size
 * @return Encode an ASCII string to UTF-8 code points.
 */
extern utf8_char *EncodeAscii(const char *string, size_t size);

/**
 *
 * @param char_
 * @return
 */
extern utf8_char EncodeAsciiChar(char char_);

/**
 *
 * @param left
 * @param right
 * @return
 */
extern int IsCharEqual(utf8_char left, utf8_char right);

/**
 *
 * @param char_
 * @return
 */
extern int ValidateChar(utf8_char char_);

/**
 *
 * @param str
 * @return
 */
extern size_t UtfStrlen(utf8_char *str);



#endif