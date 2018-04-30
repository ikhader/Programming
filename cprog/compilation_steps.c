
#include <stdio.h>

#define STR "HELLO WORLD"
#define MAX_VAL 10


int main(int argc, char *argv[])
{
  int a = MAX_VAL;
  char c[] = STR;


  printf("STEPS OF COMPILATION: \n");
  printf("\t preprocessor:  \n");
  printf("\t\t gcc -E <file_name.c> >>  <file_name.I>  \n");

  printf("\t compiler:  \n");
  printf("\t\t gcc -S <file_name.c> \n");

  printf("\t Linker:  \n");
  printf("\t\t gcc -c <file_name.c> \n");

  printf("\t Loader:  \n");
  printf("\t\t gcc -o file_name  <file_name.c> \n");
  
  printf("\t to see all preposser; assembly & ELF files with one command \n");
  printf("\t\t gcc -save-temps <file_name.c>\n");
}





