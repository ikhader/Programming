#include "bitwise.h"
#include <iostream>

using namespace std;
void bitwise_get_set_bit_cnt(int n, int &cnt)
{
  cnt = 0;
  while(n)
  {
    cnt ++;
    n &= n - 1;
  }
}

void bitwise_print_bits(int a)
{
  cout <<"@@@@ BITWISE resp: ";
  for(int i = sizeof(int) * 8 - 1; i > 0 ; i--)
  {
    if(IS_BIT_SET(a, i))
      cout<<"1";
    else
      cout << 0;
    
  }
  cout <<endl;
}
void bitwise_print_bits(unsigned char a)
{
  //cout <<"@@@@ BITWISE resp: ";
  for(int i = sizeof(char) * 8; i > 0 ; i--)
  {
    if(IS_BIT_SET(a, i))
      cout<<"1";
    else
      cout << 0;
    
  }
  cout <<endl;
}

void bitwise_copy_from_start_to_end(unsigned char &dst, unsigned char src, int spos, int epos)
{
  unsigned char num = 0;
  // cout <<"dst is:";
  // bitwise_print_bits(dst);

  // cout <<"src is:";
  // bitwise_print_bits(src);

  for(int i = spos; i < epos; i++)
  {
    num = num | (src & 1 << i);
  }
  // cout <<"num is:";
  // bitwise_print_bits(num);

  dst |= num;
  // cout <<"dst is:";
  // bitwise_print_bits(dst);

}


