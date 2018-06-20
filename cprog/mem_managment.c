

#include <stdio.h>

//int test[20], abcde = 20;
void func()
{
  printf("in the func");
}
int main(int argc, char *argv[])
{
  //static int st[20];// = 0;
  printf("Hello world \n");
  return 0;
}


/*
output: compile: gcc mem_managment.c
Command used to read: objdump -h a.out 

1. code: main(){printf ("Hello world"); return0;}
objdump -h a.out 
    a.out:	file format Mach-O 64-bit x86-64

  Sections:
  Idx Name          Size      Address          Type
  0 __text        00000034 0000000100000f50 TEXT 
  1 __stubs       00000006 0000000100000f84 TEXT 
  2 __stub_helper 0000001a 0000000100000f8c TEXT 
  3 __cstring     0000000e 0000000100000fa6 DATA 
  4 __unwind_info 00000048 0000000100000fb4 DATA 
  5 __nl_symbol_ptr 00000010 0000000100001000 DATA 
  6 __la_symbol_ptr 00000008 0000000100001010 DATA 

2. 1 + static int st[20];

  a.out:	file format Mach-O 64-bit x86-64

  Sections:
  Idx Name          Size      Address          Type
  0 __text        00000034 0000000100000f50 TEXT 
  1 __stubs       00000006 0000000100000f84 TEXT 
  2 __stub_helper 0000001a 0000000100000f8c TEXT 
  3 __cstring     0000000e 0000000100000fa6 DATA 
  4 __unwind_info 00000048 0000000100000fb4 DATA 
  5 __nl_symbol_ptr 00000010 0000000100001000 DATA 
  6 __la_symbol_ptr 00000008 0000000100001010 DATA 
  7 __bss         00000050 0000000100001020 BSS                 --> note this added 80 bytes of vaule (0x50 = 80)

3. 1 + global varaibles: int test[20]
  a.out:	file format Mach-O 64-bit x86-64

  Sections:
  Idx Name          Size      Address          Type
  0 __text        00000034 0000000100000f50 TEXT 
  1 __stubs       00000006 0000000100000f84 TEXT 
  2 __stub_helper 0000001a 0000000100000f8c TEXT 
  3 __cstring     0000000e 0000000100000fa6 DATA 
  4 __unwind_info 00000048 0000000100000fb4 DATA 
  5 __nl_symbol_ptr 00000010 0000000100001000 DATA 
  6 __la_symbol_ptr 00000008 0000000100001010 DATA 
  7 __common      00000050 0000000100001020 BSS       --> note this is added 

4. 3 + int abcd = 30;
a.out:	file format Mach-O 64-bit x86-64

Sections:
Idx Name          Size      Address          Type
  0 __text        00000034 0000000100000f50 TEXT 
  1 __stubs       00000006 0000000100000f84 TEXT 
  2 __stub_helper 0000001a 0000000100000f8c TEXT 
  3 __cstring     0000000e 0000000100000fa6 DATA 
  4 __unwind_info 00000048 0000000100000fb4 DATA 
  5 __nl_symbol_ptr 00000010 0000000100001000 DATA 
  6 __la_symbol_ptr 00000008 0000000100001010 DATA 
  7 __data        00000004 0000000100001018 DATA    --> this is added 
  8 __common      00000050 0000000100001020 BSS

5. 1 + function func(){printf("in the func");}
a.out:	file format Mach-O 64-bit x86-64

Sections:
Idx Name          Size      Address          Type
  0 __text        00000054 0000000100000f20 TEXT  --> this size changed
  1 __stubs       00000006 0000000100000f74 TEXT 
  2 __stub_helper 0000001a 0000000100000f7c TEXT 
  3 __cstring     0000001a 0000000100000f96 DATA 
  4 __unwind_info 00000048 0000000100000fb0 DATA 
  5 __nl_symbol_ptr 00000010 0000000100001000 DATA 
  6 __la_symbol_ptr 00000008 0000000100001010 DATA 
*/

