#include <stdlib.h>
#include <propeller.h>
#include "test40.h"

int32_t test40::Tx(int32_t Character)
{
  int32_t result = 0;
  _OUTA = Character;
  return result;
}

int32_t test40::Dec(int32_t Value)
{
  int32_t result = 0;
  int32_t	I, X;
  X = -(Value == (int32_t)0x80000000U);
  if (Value < 0) {
    Value = (abs((Value + X)));
    Tx('-');
  }
  I = 1000000000;
  int32_t _idx__0000;
  _idx__0000 = 10;
  do {
    if (Value >= I) {
      Tx((((Value / I) + '0') + (X * -(I == 1))));
      Value = (Value % I);
      __extension__({ int32_t _tmp_ = result; result = -1; _tmp_; });
    } else {
      if ((result) || (I == 1)) {
        Tx('0');
      }
    }
    I = (I / 10);
    _idx__0000 = (_idx__0000 + -1);
  } while (_idx__0000 >= 1);
  return result;
}

