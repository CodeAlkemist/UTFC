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
typedef struct utf8_codepoint__ {
  byte bytes[4];
} utf8_char;

/**
 * Parse a raw arbitrary amount of bytes into a utf-8 string.
 * @param bytes
 * @param size
 * @return A utf8_string corresponding to the characters identified in the bytes passed
 */
utf8_char *ParseRawBytes(byte *bytes, size_t size);
/**
 *
 * @param string
 * @param size
 * @return
 */
utf8_char *EncodeAscii(const char *string, size_t size);

#endif