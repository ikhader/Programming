
/*
Part 1: removes all duplicates from the vector string
   implementation:
     1. push each word into a map
     2. print each element out of map

Part 2: count number of occurance of each word and return their map
*/

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;
string remove_duplicates(string s)
{
  string non_rep_words;
  int startpos = 0;
  set <string> se;  

  for (int i = 0; i < s.size(); i++)
  {
    if(s[i] == ' ')
    {
      se.insert(s.substr(startpos, i - startpos));
      startpos = i + 1;
    }
  }
  
  se.insert(s.substr(startpos, s.size() - startpos));

  for (set<string>::iterator it = se.begin(); it != se.end(); it++)
  {
    non_rep_words += *it; 
    non_rep_words += ' '; 
  }
  
  return non_rep_words;
}
map<string, int> get_duplicates_count(string s)
{
  map <string, int> dup_cnt;
  int startpos = 0;
  
  for (int i = 0; i < s.size(); i++)
  {
    if(s[i] == ' ')
    {
      map<string, int>:: iterator it = dup_cnt.find(s.substr(startpos, i - startpos));
      if(it != dup_cnt.end())
        dup_cnt[s.substr(startpos, i - startpos)]++;
      else
        dup_cnt[s.substr(startpos, i - startpos)] = 1;
      startpos = i + 1;
    }
  }
  return dup_cnt;
}

int main(int argc, char *argv[])
{
  //string s("Hello how are you? are are");
  string s("ab cd ef ab ef gh");
  cout << s <<endl<< remove_duplicates(s) <<endl;
  map<string, int> dup_cnt = get_duplicates_count(s);
  for (map<string, int>::iterator it = dup_cnt.begin(); it != dup_cnt.end(); it++)
    cout << it->first << "  " << it->second <<endl;
  return 0;
}
