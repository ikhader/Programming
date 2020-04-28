

#include <iostream>
#include <vector>
#include <algorithm>
#include<unistd.h>
#include <map>

#include "array.h"

using namespace std;
/*
roates matrix in cyclic order
a[] = {1,2,3,4,5}
rot: 1 --> {2,3,4,5,1}
rot: 2 --> {3,4,5,1,2}
rot: 3 --> {4,5,1,2,3}
*/
void rotate_matrix(int a[], int rotate_counter, int array_size)
{
  int counter, iIndex;

  for(counter = 0; counter < rotate_counter; counter++)
  {
    int t = a[0];
    for(iIndex = 0; iIndex < array_size - 1; iIndex++)
    {
      a[iIndex] = a[iIndex + 1];
    }
    a[array_size - 1] = t;
  }
  
  return ;
}

/*
a[] = {1,2,3,4,5}
o/p --> {1,3,5,2,4}
*/
void even_odd_sepeartion(int a[], int array_size)
{
  int counter;
  for(counter = 0; counter < array_size; counter++)
  {
    if(a[counter]%2 == 0)
    {
      int i;
      for(i = counter + 1; i < array_size; i++)
      {
        //found odd number swap it now
        if(a[i] % 2)
        {
          int temp = a[counter];
          a[counter] = a[i];
          a[i] = temp;
          i = array_size; //no point in running again
          //1, 3, 2, 4, 5
        }
      }
    }
  }
  return;
}

void even_odd_sepeartion_ver2(int a[], int array_size)
{
  int left = 0;
  int right = array_size - 1;
  //odd in the starting
  while(left < right)
  {
    if(a[left] % 2 == 1)
    {
      left++;
    }
    if(a[right] % 2 == 0)
    {
      right--;
    }
    else
    {//swap now
      int t = a[left];
      a[left] = a[right];
      a[right] = t;
      left++;
      right--;

      // cout << "Left: " << left << " right: " <<right <<endl;
      // for (int i = 0; i < array_size; i++)
      // {
      //   cout <<"a[" << i << "] val: " << a[i] << "   ";
      // }
      // cout <<endl;

    }
    
  }
  cout <<"FINAL" <<endl;
  for (int i = 0; i < array_size; i++)
  {
    cout <<"a[" << i << "] val: " << a[i] << "   ";
  }
  cout <<endl;
}
void get_max_sum_path(int a[], int array_size, int *s, int *e)
{
  int sum, tsum;
  int start, end;
  int i, j;

  start = end = tsum = 0;
  sum = a[0];
  for(i = 0; i < array_size; i++)
  {
    tsum = a[i];
    for(j = i + 1; j < array_size; j++)
    {
      if(tsum + a[j] > sum)
      {
        sum = tsum + a[j];
        start = i;
        end = j;
        tsum = sum;
        //cout<<"Sum: "<< sum << " start: " << start << " end: " << end << endl;
      }
      if(tsum + a[j] < sum)
      {
        j = array_size;
      }
    }
  }
  //cout <<"----------------------------------------------------------" <<endl;
  if (sum < a[array_size-1])
    start = end = array_size-1;
  *s = start;
  *e = end;
  return ;
}


/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

This solution has 3 approaches
1. Brute force [ run loop within a loop and find it out]
2. using find method
3. Using hash map/sets
*/
void twoSumBruteForce(vector<int>& nums, int target, vector<int> &twoSum) 
{
    for(int i = 0; i < nums.size(); i++ )
    {
      for(int j = i + 1; j < nums.size(); j++)
      {
        if(nums[i] + nums[j] == target)
        {
          twoSum.push_back(i);
          twoSum.push_back(j);
        }

      }
    }

}

void twoSumUsingFind(vector <int> &nums, int target, vector<int>&res)
{
    for(int i = 0; i < nums.size(); i++)
    {

      /*
       auto sec = std::find( nums.begin() + i + 1, nums.end(), target - nums[i]);
            if(sec != nums.end())
            {
                s.push_back(i);
                s.push_back(sec - nums.begin() + i);
            }
      */
      auto ite = std::find(nums.begin() + i + 1, nums.end(), target - nums[i]);
      if(ite != nums.end())
      {
        res.push_back(i);
        res.push_back(ite - nums.begin());
        
      }

    }
}

/*
push all elements into a map
map[nums[i]] = i
map[value at nums[i]] = postion
now run each element on array; use map to look for matching element
*/  
void twoSumUsingMap(vector <int> &nums, int target, vector<int>&res)
{
    map<int, int> dets;

    //Populate elements and its position into map
    for(int i = 0; i < nums.size(); i++)
    {
      dets[nums[i]] = i;
    }
    for(int i = 0; i < nums.size(); i++)
    {
      auto ite = dets.find(target - nums[i]);
      if(ite != dets.end())
      {
        res.push_back(i);
        res.push_back(ite->second);

        dets.erase(nums[i]);
        dets.erase(ite);

      }
    }




     

}

