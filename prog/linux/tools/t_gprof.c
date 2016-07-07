
#include <stdio.h>

void fun_1(void)
{
  int i =0;
  for ( i = 0; i < 0xffffff; i++)
   ;
}
int main()
{

  fun_1();
  return 0;
}


