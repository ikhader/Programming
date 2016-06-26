
#include <stdio.h>

/*
rules: 
  1. find out return time (first line of the function)
  2. keep calling function
*/
int factorial(int n)
{
  if(n <= 1)
    return 1;

  return n * factorial (n - 1);
}

int main(int argc, char *argv[])
{
  printf ("fact of 6: %d\n", factorial(6));
  return 0;
}
