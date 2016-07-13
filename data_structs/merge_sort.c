#include <stdio.h>

int sort(int a[], int left, int right)
{
  int i, j;
  printf("check with limit [%d] == [%d] \n", left, right);
  for ( i = left; i <= right; i++)
  {
    for ( j = i + 1; j <= right; j++)
    {
      //compare and move values
      if(a[i] > a[j])
      {//swap
        int t = a[i];
        a[i] = a[j];
        a[j] = t; 
      }
    }
  }
}

void bubble_sort(int a[], int l, int r)
{
  int t = (l+r)/2;
  if( t <= 1 || l >= r)
    return; 
  if(l == 0)
  {
    bubble_sort(a, l, t);
    sort(a, l, t);
  }
  bubble_sort(a, t + 1, r - 1);
  sort(a, t, r);

  //full & final merge all of them
  sort(a, l, r);
}


int main(int argc, char *argv[])
{
  int a[] = {90, 10, 50, 60, 100, 20, 5, 110, -1};
  int i = 0;

  printf("before sorting \n");
  for( i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    printf(" %d ", a[i]);
  printf("\n");
  
  bubble_sort(a, 0, sizeof(a)/sizeof(a[0]));

  printf("after sorting \n");
  for( i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    printf(" %d ", a[i]);
 
  printf("\n");
  return 0;
}

