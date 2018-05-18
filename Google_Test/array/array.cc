

#include <iostream>


#include "array.h"

using namespace std;
/*
roates matrix in cyclic order
a[] = {1,2,3,4,5}
rot: 1 --> {2,3,4,5,1}
rot: 2 --> {3,4,5,1,2}
rot: 3 --> {4,5,1,2,3}
*/
void rotate_matrix(int a[], int rotate_counter, int array_size)
{
  int counter, iIndex;

  for(counter = 0; counter < rotate_counter; counter++)
  {
    int t = a[0];
    for(iIndex = 0; iIndex < array_size - 1; iIndex++)
    {
      a[iIndex] = a[iIndex + 1];
    }
    a[array_size - 1] = t;
  }
  
  return ;
}

/*
a[] = {1,2,3,4,5}
o/p --> {1,3,5,2,4}
*/
void even_odd_sepeartion(int a[], int array_size)
{
  int counter;
  for(counter = 0; counter < array_size; counter++)
  {
    if(a[counter]%2 == 0)
    {
      int i;
      for(i = counter + 1; i < array_size; i++)
      {
        //found odd number swap it now
        if(a[i] % 2)
        {
          int temp = a[counter];
          a[counter] = a[i];
          a[i] = temp;
          i = array_size; //no point in running again
          //1, 3, 2, 4, 5
        }
      }
    }
  }
  return;
}

void get_max_sum_path(int a[], int array_size, int *s, int *e)
{
  int sum, tsum;
  int start, end;
  int i, j;

  start = end = tsum = 0;
  sum = a[0];
  for(i = 0; i < array_size; i++)
  {
    tsum = a[i];
    for(j = i + 1; j < array_size; j++)
    {
      if(tsum + a[j] > sum)
      {
        sum = tsum + a[j];
        start = i;
        end = j;
        tsum = sum;
        cout<<"Sum: "<< sum << " start: " << start << " end: " << end << endl;
      }
      if(tsum + a[j] < sum)
      {
        j = array_size;
      }
    }
  }
  cout <<"----------------------------------------------------------" <<endl;
  if (sum < a[array_size-1])
    start = end = array_size-1;
  *s = start;
  *e = end;
  return ;
}
