#include <propeller.h>
#include "test107.h"

uint8_t test107::dat[] = {
  0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x00, 
};
int32_t test107::Main(void)
{
  return ((uint8_t *)&dat[0])[0];
}

