#include <iostream>
#include <string>

using namespace std;

/*
 * Checks if a second string is made out of rotation process of first string
 * ex: bottleneck -- ttleneckbo -- neckbottle
 * Algo: append the source string again & search for second string
 * Ex: string_1: bottleneck  string_2: neckbottle
 *     temp = string_1 + string_1 => bottleneckbottleneck
 *     search for string_2 in temp.
*/

bool is_string_rotation_good(string s1, string s2)
{
  if (s1.length() != s2.length())
    return false;

  string t = s1 + s1;
  bool is_available = false;

  size_t npos = t.find(s2);
  if (t.npos == npos)
    is_available = false;
  else
    is_available = true;

  return is_available;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout<<"Format: string_1 & string_2" <<endl;
    return 1;
  }
  cout <<"Is string rotated form: " << is_string_rotation_good(argv[1], argv[2]) << endl;

  return 0;
}
