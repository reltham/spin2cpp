#include <propeller.h>
#include "test23.h"

int32_t test23::Start(void)
{
  int32_t R = 0;
  int32_t	X;
  X = locknew();
  R = lockclr(X);
  return R;
}

