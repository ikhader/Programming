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

void bitwise_copy_from_start_to_end(int dst, int src, int spos, int epos)
{
  int num = 0;
  for(int i = spos; i < epos; i++)
  {
    num = num | (src & 1 << i);
  }
  dst |= num;

}


