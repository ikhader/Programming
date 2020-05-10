#ifndef __ARRAY_MATRIX__
#define __ARRAY_MATRIX__
#include <vector>
#include <map>
using namespace std;
void rotate_matrix(int array[], int rotate_counter, int array_size);
void even_odd_sepeartion(int a[], int array_size);
void even_odd_sepeartion_ver2(int a[], int array_size);
void get_max_sum_path(int a[], int array_size, int *s, int *e);
//void btree_get_left_view(stnode *h, vector<int> &res);

void twoSumBruteForce(std::vector<int> &nums, int target, std::vector<int> &twoSum);
void twoSumUsingFind(std::vector<int> &nums, int target, std::vector<int> &twoSum);
void twoSumUsingMap(vector <int> &nums, int target, vector<int>&res);
void max_subarray_sum(vector <int> nums, int &total);
#endif// __ARRAY_MATRIX__
