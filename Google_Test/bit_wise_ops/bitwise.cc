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

/*
char: 
i/p: a | b | c | d | e | f | g | h |
o/p: h | g | f | e | d | c | b | a |

check if both bits are NOT set; then flip them 
*/

void flip_nibble(unsigned char &c)
{
  const int max_loop = sizeof(unsigned char) * 8;

  printf("original: ");
  bitwise_print_bits(c);

  for (int i = 0; i < max_loop/2 ; i++)
  {
    if (IS_BIT_SET_ZERO_BASED(c, i) != IS_BIT_SET_ZERO_BASED(c, max_loop - 1 - i))
    {
      FLIP_BIT_ZERO_BASED(c, i);
      FLIP_BIT_ZERO_BASED(c, max_loop - 1 - i);
      //printf("iteration [%d]: \n", i);
      //bitwise_print_bits(c);

    }
  }
  printf("FLIPPED:  ");
  bitwise_print_bits(c);

}
