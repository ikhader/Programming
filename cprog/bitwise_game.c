#include <stdio.h>

#define IS_BIT_SET(c, pos) (c & (1 << pos -1)) 
#define SET_BIT(c, pos) (c |= (1 << pos -1)) 
#define UNSET_BIT(c, pos) (c &= ~(1 << pos -1)) 
#define FLIP_BIT(c, pos) (c ^= (1 << pos -1)) 

void print_bits(char a)
{
  int i ;
  
  for (i = 8; i >= 1; i--)
  if (IS_BIT_SET(a, i))
    printf(" 1 ");
  else
    printf(" 0 ");

  printf("\n");
}

int get_num_of_bits_set(char a)
{
  int cnt = 0, i;
  
  for(i = 0; i < 8; i++)
  {
    if(IS_BIT_SET(a, i))
      cnt++;
  }
  return cnt;
}

int main(int argc, char *argv[])
{
  char c = 2;
  printf ("playing with bit wise opeartors \n");

  printf("binary format for %d: \n", c);
  print_bits(c); 

  SET_BIT(c, 3);
  printf("3rd bit set: binary format for %d: \n", c);
  print_bits(c); 

  UNSET_BIT(c, 3);
  printf("3rd bit UNset: binary format for %d: \n", c);
  print_bits(c); 
  
  FLIP_BIT(c, 3);
  printf("3rd bit FLIP: binary format for %d: \n", c);
  print_bits(c); 

  FLIP_BIT(c, 3);
  printf("3rd bit FLIP: binary format for %d: \n", c);
  print_bits(c); 

  SET_BIT(c, 4);
  printf("[%d] bits are set \n", get_num_of_bits_set(c));
  print_bits(c); 

}


