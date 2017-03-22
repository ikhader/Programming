#include <iostream>
#include <string>
#include <vector>
#include <iterator>

/*
 * well explained at
 * http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
 *possibel combinations of "abc"
 *------------------abc--------------
 *           /        |          \
 *swap:    a-a      a-b          a-c
 *    [a]bc|[a]cb [b]ac|[b]ca [c]ba [c]ab
 *
 *
 * */

using namespace std;

void swap(string &s, int p1, int p2)
{
  if (p1 >= s.length() || p2 > s.length() || p1 == p2 || s[p1] == s[p2])
    return;
  char ch = s[p1];
  s[p1] = s[p2];
  s[p2] = ch;
}

void possible_combinations(string &s, unsigned int pos1, unsigned int pos2, vector<string> &combs)
{
  if (pos1 == pos2)
  {
    combs.push_back(s);
    return;
  }
  for (int i = pos1; i <= pos2; i++)
  {
    swap(s, pos1, i);
    possible_combinations(s, pos1 + 1, pos2, combs);
    swap(s, pos1, i); //rollback time
  }
}

int main(int argc, char *argv[])
{
  string s = "abcdefgijk";
  vector<string> combinations;
  possible_combinations(s, 0, s.length() - 1, combinations);
  cout<<"Length: " << combinations.size() <<endl;
/*
 * cout<<"Possible combinations for: " << s <<endl;
  for(vector<string>::iterator it = combinations.begin(); it != combinations.end(); it++)
    cout <<*it <<endl;
*/
}
