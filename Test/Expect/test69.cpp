#include <propeller.h>
#include "test69.h"

int32_t test69::Demo(void)
{
  int32_t result = 0;
  if (!(((_INA >> 0) & 0x1))) {
    abort();
  }
  return result;
}

