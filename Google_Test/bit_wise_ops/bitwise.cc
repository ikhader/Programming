#include "bitwise.h"

void bitwise_get_set_bit_cnt(int n, int &cnt)
{
  cnt = 0;
  while(n)
  {
    cnt ++;
    n &= n - 1;
  }

  
}


