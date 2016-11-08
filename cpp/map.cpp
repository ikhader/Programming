#include <iostream>
#include <map>

using namespace std;

void print_map(map<string, int> m)
{
  cout <<"MAP: " <<endl;
  for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    cout<<it->first << "  " <<it->second <<endl;
}
/*
 * print map
 * add elements to map
 * delete elements map
 * manuplate
 * merge from another map
 *
 */
void map_manuplations(map<string, int> &m)
{
  print_map(m);

  m["d"] = 50;
  cout<<"After adition: " <<endl;
  print_map(m);

  cout<<"After erase 'c': " <<endl;
  m.erase("c");
  print_map(m);
  m.erase("c");

  cout<<"After change 'a'to 100:  " <<endl;
  m["a"] = 100;
  print_map(m);

  map<string, int>dummy;
  dummy["e"] = 60;
  dummy["f"] = 70;
  dummy["a"] = 10;
  dummy["g"] = 80;

  m.insert(dummy.begin(), dummy.end());
  cout<<"After merging two identical hasehs:  " <<endl;
  print_map(m);
}


int main (int argc, char *argv[])
{
  map<string, int> m;
  m["a"] = 10;
  m["b"] = 20;
  m["c"] = 30;
  map_manuplations(m);
}
