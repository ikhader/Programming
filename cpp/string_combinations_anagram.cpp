#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * @swap: will swap characters at pos1 & pos2 in string
 * @arg-1: str ==> source string
 * @arg-2: pos1 ==> swap postion-1
 * @arg-3: pos2 ==> swap postion-2
*/
void swap(string &str, int pos1, int pos2)
{
    char temp;
    if(pos1 == pos2)
      return;
    temp = str[pos1];
    str[pos1] = str[pos2];
    str[pos2] = temp;
}

/*
 * @print_string_combinations: prints all possible combinations of str
 * @arg1: str source string, whose combinations needs to be printed
 * @arg2: start_index, start postion of string usually zero
 * @arg3: end_index, end position of string usually string length -1; Remeber index of string starts from zero
 * @arg4: cnt -- number of possible combinations
*/
void print_string_combinations(string str, int start_index, int end_index, int *cnt)
{
   int i;
   if (start_index == end_index)
   {
     *cnt = *cnt + 1;
     cout <<str << " cnt " << *cnt <<endl;
   }
   else
   {
       for (i = start_index; i <= end_index; i++)
       {
          swap(str, start_index, i);
          print_string_combinations(str, start_index + 1, end_index, cnt);
          swap(str, start_index, i);
       }
   }
}

/*
 * @get_string_combinations: gets all possibel combinations of a string & adds them to vector of strings
 * @arg1: str source string, whose combinations needs to be printed
 * @arg2: start_index, start postion of string usually zero
 * @arg3: end_index, end position of string usually string length -1; Remeber index of string starts from zero
 * @arg4: combinations, all possible combinations of str
*/

void get_string_combinations(string str, int start_index, int end_index, std::vector<std::string> &combinations)
{
   int i;
   if (start_index == end_index)
   {
     combinations.push_back(str);
   }
   else
   {
     for (i = start_index; i <= end_index; i++)
     {
        swap(str, start_index, i);
        get_string_combinations(str, start_index + 1, end_index, combinations);
        swap(str, start_index, i);
     }
   }
}

/*
 * This function searches from anagram of needle in haystack
 * Algo:
 *   1. generate all possible combinations of needle
 *   2. search for all possible words in haystack
 *   3. if <2> found copy position; move fwd (pos + needle.length) & check again
 *   4. else <2> keep searching
 *
 */
vector<size_t> get_anagram_check(string haystack, string needle)
{
   int count = 0;
   std::vector<std::string> combinations ;
   vector<size_t> positions;

   get_string_combinations(needle, 0, needle.length() - 1, combinations);
   for (vector<string>::iterator it = combinations.begin(); it != combinations.end(); it++)
   {
     size_t pos = 0;
     bool bDone = false;
     while(!bDone)
     {
       pos = haystack.find(*it, pos);
       if(pos == haystack.npos)
       {
         bDone = true;
       }
       else
       {
         positions.push_back(pos);
         pos = pos + needle.length();
       }
     }
   }
   return positions;

}

/*
@test inputs
*/
int main()
{
    string str("ABCD");
    int cnt = 0;
    print_string_combinations(str, 0, str.length()-1, &cnt);
    cout<<"total combinations for " <<str<< " is: "<< cnt <<endl;

    string haystack("abab");
    string needle("ab");
    cout<<"positions of  " << needle << " anagram in: " << haystack << endl;
    vector<size_t> combs = get_anagram_check(haystack, needle);
    for(vector<size_t>::iterator it = combs.begin(); it != combs.end(); it++)
    {
      cout<<"value: " <<*it<<endl;
    }
    return 0;
}
