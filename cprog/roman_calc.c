#include <stdio.h>
#include <string.h>
#include <malloc.h>

int is_valid_buffer(char *buffer, char *allowed_chars)
{
  register i, j;
  int bfound = 0;
  for (i = 0; i < strlen(buffer); i++)
  {
    bfound = 0;
    //check for each char to match
    for (j = 0; j < strlen(allowed_chars); j++)
    {
      if(allowed_chars[j] == buffer[i])
      {
        bfound = 1;
        break;
      }
    }
    //character not found
    if(!bfound)
    {
      printf("INVALID characters\n");
      return 0;  
    }
  }
  return 1;
}

int convert_roman_2_decimal(char *roman_num)
{
  int roman_num_len = strlen(roman_num);
  int i, decimal_num;
  int a[50];
  for( i = 0; i < roman_num_len; i++)
  {
    int v = -1;
    switch(roman_num[i])
    {
      case 'I': v = 1; break;
      case 'V': v = 5; break;
      case 'X': v = 10; break;
      case 'L': v = 50; break;
      case 'C': v = 100; break;
      case 'D': v = 500; break;
      case 'M': v = 1000; break;
    }
    if (v == -1)
    {
      printf("[%s]invalid number\n", roman_num);
      return ;
    }
    a[i] = v;
  }
  decimal_num = a[roman_num_len -1]; 
  for (i = roman_num_len - 1; i > 0; i--)
  {
    if(a[i] > a[i-1])
      decimal_num = decimal_num - a[i - 1];
    else
      decimal_num = decimal_num + a[i - 1];
  }
  printf("Roman[%s] == decimal [%d]\n", roman_num, decimal_num);
  return decimal_num;
}

char* convert_decimal_2_roman(int decimal_num)
{
  int t = decimal_num;
  int decimal_numbers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
  char * roman_symbols[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" }; 
  char *roman_number = (char*) malloc(sizeof(char) * 64);
  int i = 0;
  while (decimal_num)
  {   
    while (decimal_num/decimal_numbers[i])
    {
      strcat(roman_number, roman_symbols[i]); 
      decimal_num -= decimal_numbers[i];  
    }
    i++;
  }
  printf("decimal[%d] == roman[%s] \n", t, roman_number);
  return (char *)roman_number;
}

char* roman_math(char *input_buffer)
{
  char allowed_roman_chars[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  char allowed_math[] = {'+', '-'};
  char *allowed_chars;
  char *num_1, *num_2;
  int iIndex, startpos, is_first_number_found = 0;
  int result = 0;
  
  //validate buffer
  allowed_chars = (char*) malloc(strlen(allowed_roman_chars) + strlen(allowed_math) + 1 ) ;
  if(!allowed_chars)
  {
    printf("memory not avilable");
    return "MEMORY ISSUE"; 
  } 
  strcpy(allowed_chars, allowed_roman_chars);
  strcat(allowed_chars, allowed_math);
  if(!is_valid_buffer(input_buffer, allowed_chars))
  {
    printf("not a valid buffer");
    free((void*)allowed_chars);
    return "INVALID BUFFER"; 
  }

  free((void*)allowed_chars);

  num_1 = (char*) malloc(strlen(input_buffer));
  num_2 = (char*) malloc(strlen(input_buffer));
  
  startpos = 0;
  //printf("Roman math: %s \n", input_buffer);
  for (iIndex = 0; iIndex < strlen(input_buffer); iIndex++)
  {
    if(input_buffer[iIndex] == '+' || input_buffer[iIndex] == '-')
    {
     // if(!is_first_number_found)
      {
        strncpy(num_1, input_buffer+ startpos, iIndex - startpos );
        is_first_number_found = 1;
        result += convert_roman_2_decimal(num_1);
        memset(num_1, 0x00, strlen(input_buffer));
      }
//      else
//      {
//        strncpy(num_2, input_buffer + startpos, iIndex - startpos );
 //       is_first_number_found = 0;
  //      result += convert_roman_2_decimal(num_2);// + convert_roman_2_decimal(num_1);
   //   }
      startpos = iIndex + 1;
    }
  }  
  strncpy(num_1, input_buffer + startpos, iIndex - startpos );
  result += convert_roman_2_decimal(num_1);// + convert_roman_2_decimal(num_1);

  free((void*)num_1);
  free((void*)num_2);

  return convert_decimal_2_roman(result);
}
int main(int argc, char *argv[])
{
  char c[] = "C+XD";
  char q[] = "C+XD+XXI";
  char h[] = "hello world";
  //int res;
  //int d = 5212;
//  char *c = convert_decimal_2_roman(d);
//  printf("Roman number of [%d] is: [%s]\n", d, c);
//  res = convert_roman_2_decimal(c);
//  printf("decimal number of [%s] is: [%d]\n", c, res);
//  printf("math on [%s] is [%s]\n ",h, roman_math(h));
//  printf("math on [%s] is [%s]\n ",c, roman_math(c));
  printf("math on [%s] is [%s]\n ",q, roman_math(q));
  return 0;  
}




