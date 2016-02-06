#include <propeller.h>
#include "test63.h"

#ifdef __GNUC__
#define INLINE__ static inline
#define PostEffect__(X, Y) __extension__({ int32_t tmp__ = (X); (X) = (Y); tmp__; })
#else
#define INLINE__ static
static int32_t tmp__;
#define PostEffect__(X, Y) (tmp__ = (X), (X) = (Y), tmp__)
#endif

void test63::Test(int32_t Exponent)
{
  if (Exponent == 0) {
    (++Exponent);
  } else if (1) {
    (--Exponent);
  }
}

