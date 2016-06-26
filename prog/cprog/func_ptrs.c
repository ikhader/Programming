
#include <stdio.h>

typedef int (*sum_fptr)(int, int);

int sum(int a, int b)
{
  return a + b;
}


int main(int argc, char *argv[])
{
  sum_fptr s = sum;
  printf("sum is: %d\n", s(10,20));
  return 0;

}

