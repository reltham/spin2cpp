#include <propeller.h>
#include "test44.h"

int32_t test44::Fun(int32_t X, int32_t Y)
{
  int32_t result = 0;
  if (X == 10) {
    if (Y == 0) {
      _OUTA ^= 0x1;
    } else if (Y == 1) {
      _OUTA ^= 0x2;
    }
  } else if (X == 20) {
    _OUTA ^= 0x4;
  } else if (1) {
    _OUTA ^= 0x8;
  }
  return result;
}

