#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
 * Checks if in a given string can we form a polindrome combination of strings or not
 * Ex: Tact Coa: taco cat -- atco cta
 *     abcdedcba: abcdeabcd
 * Algo: 1. check each character count. 
 *       2. all the characters count must be available in even numbers or
 *       3. all characters count must be even number and one odd number
 * Ex:  abcddcba: is a polindrome
 *                  a's ==> 2
 *                  b's ==> 2
 *                  c's ==> 2
 *                  d's ==> 2
 *      aeebcddcbea: is a polindrome
 *                  a's ==> 2
 *                  b's ==> 2
 *                  c's ==> 2
 *                  d's ==> 2
 *                  e's ==> 3
 *
*/

//step-1
void get_char_cnt_map(string s, map<char, int> &perm_comb)
{
  map<char, int>::iterator it;
  //step -1 -- start 
  for(int i = 0; i < s.length(); i++)
  { 
    char ch = s[i];
    it = perm_comb.find(ch);
    if(perm_comb.end() == it)
    {//first time found the character
      perm_comb[ch] = 1;
    }
    else
    { //already added, so increment count
      perm_comb[ch] = perm_comb[ch] + 1 ;
    }
  }

}

//step-2 or step -3 validation
bool is_polindrom_permutation(string s)
{
  map<char, int> perm_comb;

  get_char_cnt_map(s, perm_comb);
 
  //check for step2/step3
  bool is_odd_cnt = false;
  for(map<char, int>::iterator it = perm_comb.begin(); it != perm_comb.end(); it++)
  {
     if (it->second % 2 != 0)
     {
       if (!is_odd_cnt)
         is_odd_cnt = true;
      else
         return false;
     }
  }
  
  return true;
}

/*
apart from the above mentioned algo, this function will also generates all polyndorme into dst
*/
bool polindrom_permutation(string src, string &dst)
{
  map<char, int> perm_comb;
  bool is_poly = true;

  get_char_cnt_map(src, perm_comb);

  bool is_odd_cnt = false;
  for(map<char, int>::iterator it = perm_comb.begin(); it != perm_comb.end(); it++)
  {
     if (it->second % 2 != 0)
     {
       if (!is_odd_cnt)
       {
         is_odd_cnt = true;

         string t;
         for(int i = 0; i < it->second; i++)
           t += it->first;
         dst.assign(t);
       }
      else
      {
        is_poly = false;
        break;
      }
     }
  }
  
  if (is_poly)
  {
    for(map<char, int>::iterator it = perm_comb.begin(); it != perm_comb.end(); it++)
    {
      if(0 == it->second%2)
      {
         for(int i = 0; i < it->second/2; i++)
         {
           dst.insert(dst.begin(), 1, it->first);
           dst.insert(dst.end(), 1, it->first);
         }
      }
    }
  } 
  return is_poly;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cout<<"Usage: string - to validate permutations" <<endl;
    return 1;
  }
  
  cout << "is_polidrom_perm possible: " << is_polindrom_permutation(argv[1]) <<endl;
  string dst;
  if(polindrom_permutation(argv[1], dst))
    cout<<"one of the polindrom is: "<< dst <<endl;
  return 0;
}
