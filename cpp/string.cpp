#include <iostream>
#include <string>

using namespace std;
/*
 * string example
 * accepts a string
 *   adds
 *   modify
 *   deletes elements
 *
*/

string string_manuplations(string &s)
{
  cout <<"Input: " <<s <<endl;

  s.append(" JUNK WORLD");
  cout <<"append: " <<s <<endl;

  s+= " DUPLICATE WORLD";
  cout <<"+=: " <<s <<endl;

  cout <<"Size is: "<< s.size() <<endl;

  string dumm = "dummy";
  string du("DUPLICATE");

  size_t pos = s.find(du);
  if (s.npos != pos )
    cout <<"DUPLICATE AT: "<< pos <<endl;
  else
    cout << du<< " NOT FOUND"<<endl;

  pos = s.find(dumm);
  if (s.npos != pos )
    cout <<dumm<< "AT: "<< pos <<endl;
      else
    cout << dumm<<" NOT FOUND"<<endl;

  //replace "DUPLICATE" with dummy
  cout <<"After Duplicate  : " <<s <<endl;
  s.replace(s.find(du), du.size(), dumm);
  cout <<"replace DUPLICATE: " <<s <<endl;

  //append string to it
  s = s + du + dumm;

  //iterator example
  cout <<"ITERATOR: " <<endl;
  for (string::iterator it = s.begin(); it != s.end(); it++)
    cout << *it;
  cout <<endl;

  return s;
}

int main(int argc, char *argv[])
{
  string s = "HELLO WORLD";
  string_manuplations(s);
  cout <<"After manuplations: " <<s <<endl;
}

