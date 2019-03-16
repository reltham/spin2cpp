/*
 * Copyright 2012 Total Spectrum Software Inc.
 * Redistribution is permitted under the terms of the MIT license
 */

#include <wchar.h>
#include <errno.h>
#include "util.h"

/* convert multibyte sequence to single wide character; UTF-8 version */

/* process a single multibyte sequence to return a wide character
 * returns:
 * count of bytes consumed if a valid character is seen
 * -1 if an error happens (invalid sequence)
 * -2 if more data remains
 */

size_t
from_utf8(wchar_t *wcptr, const char *cptr, size_t n)
{
  unsigned left;
  unsigned total;
  unsigned wch;
  unsigned minch;
  unsigned char c;
  size_t count = 0;

  left = 0;
  total = 0;
  wch = 0; 

  if (!cptr) {
    if (left) goto invalseq;
    return 0;
  }
  if (left == 0) {
    if (count >= n) {
      return (size_t)-2;
    }
    c = *cptr++; ++count;
    if (c <= 127) {
      wch = c;
      if (wch == 0)
	count = 0;
      goto return_char;
    } else if ( (c & 0xC0) == 0x80 ) {
      goto invalseq;
    } else if ( (c & 0xE0) == 0xC0 ) {
      wch = c & 0x1f;
      total = 2;
    } else if ( (c & 0xF0) == 0xE0 ) {
      wch = c & 0x0f;
      total = 3;
    } else if ( (c & 0xF8) == 0xF0 ) {
      wch = c & 0x7;
      total = 4;
    } else {
      goto invalseq;
    }
    left = total-1;
  }

  while (left > 0 && count < n) {
    c = *cptr++; ++count;
    if ((c & 0xC0) != 0x80) goto invalseq;
    wch = (wch << 6) | (c & 0x3f);
    --left;
  }

  /* did we read a whole character? */
  if (left == 0) goto validate_char;

  /* we have a partial character here */
  return (size_t)-2;

 validate_char:
  /* validate that there is no shorter sequence for the character */
  switch (total) {
  case 2:
    minch = 0x7f;  /* 7 bits */
    break;
  case 3:
    minch = 0x7ff; /* 11 bits */
    break;
  default:
    minch = 0xffff; /* 16 bits */
    break;
  }
  if (wch <= minch)
    goto invalseq;
  /* clamp to the maximum valid Unicode character */
  if (wch > 0x10ffff)
    goto invalseq;

  /* now fall through to return character */
 return_char:
  if (wcptr) *wcptr = wch;
  return count;

 invalseq:
  errno = EILSEQ;
  return (size_t)-1;
}
