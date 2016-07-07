#include <stdio.h>

void reverse(char *s, int len)
{
  char ch;
  int i = 0;
  for (i = 0; i < len/2; i++)
  {
    ch = s[i];
    s[i] = s[len - i - 1];
    s[len-i-1] = ch;
  }
  
}

int xstrlen(char *s)
{
  int i = 0;
  while(s[i])
    i++;
  return i;
}

void redable_reverse(char *s)
{
  int startpos, endpos;
  startpos = endpos = 0;
  reverse(s, xstrlen(s));
  while(s[endpos])
  {
    if(s[endpos] == ' ' || s[endpos]  == '\t')
    {
      reverse(s + startpos, endpos - startpos);
      startpos = endpos;
    }
    endpos++;
  }
  reverse(s + startpos, endpos - startpos);
}

int main(int argc, char *argv[])
{
  char s[] = "hello world, how are you?";
  printf("original is [%s]", s);
  redable_reverse(s);
  printf("reverse [%s] \n", s);
  return 0; 
}
