
#include <iostream>
#include "string_operations.h"

using namespace std;

int xstrlen(char *s)
{
  int len = 0;
  while(s[len] != '\0')
  {
    len++;
  }
  return len;
}

char* xstrrev(char *s, int len)
{
  if ( NULL == s)
    return NULL;

  if (-1 == len)
    len = xstrlen(s);

  int index = 0;

  for (int index = 0; index < len/2; index++)
  {
    char ch = s[index];
    s[index] = s[len - index -1];
    s[len - index -1] = ch;
  }
  return s;
}

char *readable_reverse(char *s)
{
  if (NULL == s)
    return NULL;
  
  //cout << "readable_reverse @ 1: " << s<<endl;
  int l = xstrlen(s);
   
  xstrrev(s, l);
  //cout << "readable_reverse @ 2: " << s<<endl;

  int start_pos, end_pos ;
  bool is_crlf_found = false;

  start_pos = end_pos = 0;
  while(s[end_pos])
  {
    if(s[end_pos] == ' ' || s[end_pos] == '\t' || s[end_pos] == '\n')
    {
      xstrrev(s + start_pos, end_pos - start_pos); //dont worry about CRLF
      //cout << "readable_reverse @ 3: " << s<<endl;
      start_pos = end_pos + 1; 
      is_crlf_found = true;
    }
    end_pos++;
  }
  if(is_crlf_found)
  {
    xstrrev(s + start_pos, end_pos - start_pos); //dont worry about CRLF
    //cout << "readable_reverse @ 4: " << s<<endl;
  }

  //cout << "readable_reverse @ 5: " << s<<endl;
  return s;
}
 
/*
checks if s2 is rotated form of s1 or not
ex: s1 = abcd s2 cdab -- true
    s1 = abcdefg s2 cdefgab -- true
    s1 = abcd s2 dcba -- false
Algo: concatenate s1 to itself; then look for s2 in it
*/ 
bool is_string_rotated(char *s1, char *s2)
{
  if(NULL == s1 || NULL == s2)
    return false;

  if(xstrlen(s1) != xstrlen(s2))
    return false;

  char *tmp_s1 = (char*)malloc(xstrlen(s1)*2 + 1);
  if(NULL == tmp_s1)
    return false;

  memset(tmp_s1, 0x00, xstrlen(s1)*2 + 1);
  strcpy(tmp_s1, s1);
  strcat(tmp_s1, s1);
  
  bool is_rotated = !(strstr(tmp_s1, s2) == NULL);

  free(tmp_s1);

  return is_rotated;
}

int main_(int argc, char *argv[])
{
  char s[] = "HELLO";
  int l = xstrlen(s); 
  cout << "Len of HELLO: "<< l <<endl;
}
