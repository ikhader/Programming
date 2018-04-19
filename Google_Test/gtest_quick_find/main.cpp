#include <iostream>
#include "quick_find.h"


int main(int argc, char *argv[])
{

  quick_find *quf = new quick_find(5);

  quf->print_array();

  quf->connect_nodes(1,3);
  quf->print_array();

  cout<<"(1,3) is connected:" <<quf->is_connected(1,3)<<endl;
  cout<<"(2,3) is connected:" <<quf->is_connected(2,3)<<endl;

  delete quf;

  return 0;
  
}