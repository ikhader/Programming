#include <stdio.h>
#include <string.h>

void swap(char *string, int pos1, int pos2)
{
    char temp;
    if(pos1 == pos2)
      return;
    temp = string[pos1];
    string[pos1] = string[pos2];
    string[pos2] = temp;
}

void print_string_combinations(char *string, int start_index, int end_index, int *cnt)
{
   int i;
   if (start_index == end_index)
   {
     *cnt = *cnt + 1;
     printf("%s  cnt[%d]\n", string, *cnt);
   }
   else
   {
       for (i = start_index; i <= end_index; i++)
       {
          swap(string, start_index, i);
          print_string_combinations(string, start_index + 1, end_index, cnt);
          swap(string, start_index, i);
       }
   }
}

int main()
{
    char str[] = "ABCD";
    int cnt = 0;
     int n = strlen(str);
    print_string_combinations(str, 0, n-1, &cnt);
    printf("total combinations: %d \n", cnt);
    return 0;
}

