
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
  
  printf("GOOD TO KNOW MORE OPTIONS \n");
  printf("gcc -Wall <file_name.c> shows all warnings \n");
  printf("gcc -l <shared_object_file name> <file_name.c> links <shared_object_filename> with <file_name> elf \n");
  
  printf("To define (__DEBUG__) macro during compile time \n");
  printf("gcc -D__DEBUG__ <file_name.c> \n");
  
  printf("To treat warnings as errors use -Werror option \n");
  printf("gcc -Werror <file_name.c> \n");  
}





