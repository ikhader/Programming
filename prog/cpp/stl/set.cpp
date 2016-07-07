
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
int main(int argc, char *argv[])
{
  set<std::string> s;
  s.insert("hello");
  s.insert("world");
  s.insert("hello");
  s.insert("world");
  cout<< "Set example:" << endl;
  for (set<string>::iterator it = s.begin(); it != s.end(); it++)
  {
    cout<< *it <<endl;
  }
  
  //multiset
  multiset<std::string> ms;
  ms.insert("hello");
  ms.insert("world");
  ms.insert("hello");
  ms.insert("world");
  cout<< "multi example:" << endl;
  for (multiset<string>::iterator it = ms.begin(); it != ms.end(); it++)
  {
    cout<< *it <<endl;
  }

  //map example
  map<string, int > m;
  m["hello"] = 10;
  m["world"] = 20;
  m["hello"] = 30;
  m["world"] = 40;
  cout<< "MAP example:" << endl;
  for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
  {
    cout<< it->first << "==" << it->second <<endl;
  }

  //multi map example
  multimap<string, int > p;
  p.insert(pair<string, int> ("hello",  10));
  p.insert(pair<string, int> ("world",  20));
  p.insert(pair<string, int> ("hello",  30));
  p.insert(pair<string, int> ("world",  40));
  cout<< "MULTI MAP example:" << endl;
  for (map<string, int>::iterator it = p.begin(); it != p.end(); it++)
  {
    cout<< it->first << "==" << it->second <<endl;
  }
  return 0;
}





