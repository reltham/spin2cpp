#include <propeller.h>
#include "test60.h"

int32_t test60::Func(int32_t A, int32_t B)
{
  int32_t Ok = 0;
  if (A < B) {
    Ok = -1;
  } else {
    if (A == 0) {
      Ok = -1;
    } else {
      Ok = 0;
    }
  }
  return Ok;
}

