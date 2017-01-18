#include <iostream>
#include <vector>
#include <stdio.h>
#include <malloc.h>

using namespace std;



typedef struct __node
{
  int data;
  struct __node *l;
  struct __node *r;
}stnode;

stnode * binarytree_createnode(int data)
{
  stnode *pnode = (stnode*) malloc(sizeof(stnode));
  if(!pnode)
    return NULL;
  pnode->data = data;
  pnode->l = NULL;
  pnode->r = NULL;
 
  return pnode;  
}

void print_int_vector(vector<int> v)
{
  cout<<"vector is : " <<endl;
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    cout << *it << "\t";
  }
  cout<<endl;
}

/*
 * This routing will check for the nodes in a binary tree(h) that add upto sum (check_sum)
 * Copies all such combinations to main_map. 
 * @ h -- head of binary tree
 * @ check_sum -- sum that must be checked against
 * @ current_sum -- sum of the elements upto this node
 * @ main_map -- all the possibel combinations are copied into this with a  SEPRATOR 
 * @ tracking_map - tracks elements that are being traversed
*/
#define SEPRATOR 0x2D
void get_sum_path(stnode *h, int check_sum, int current_sum, vector<int> &main_map, vector<int> &tracking_map)
{
  tracking_map.push_back(h->data);

  current_sum += h->data;
  //cout <<"Running on: " << h->data << " Sum is: " << current_sum <<endl;
  if(current_sum == check_sum)
  {
    //copy tracking_map to main_map
    for (vector<int>::iterator it = tracking_map.begin(); it != tracking_map.end(); it++)
    {
      main_map.push_back(*it);
    }
   // print_int_vector(tracking_map);
    main_map.push_back(SEPRATOR);
  }
  
  if(h->l)
    get_sum_path(h->l, check_sum, current_sum, main_map, tracking_map);
  if(h->r)
    get_sum_path(h->r, check_sum, current_sum, main_map, tracking_map);

  current_sum -= h->data;
  tracking_map.pop_back();

}

/*
 * This function will return all possible combinations in a binary tree (always from root) that would add upto sum(check_sum)
 * @ h - head of binary tree
 * @ check_sum - reference sum that must be met
 * @ main_map - map that maintains all combinations
*/
void get_possible_combinations_for_sum_always_with_root(stnode *h, int check_sum, vector<int> &main_map)
{
   vector<int> tracking_vector;
   get_sum_path(h, check_sum, 0, main_map, tracking_vector);
}

/*
 * This function will return all possible combinations in a binary tree that would add upto sum(check_sum)
 * @ h - head of binary tree
 * @ check_sum - reference sum that must be met
 * @ main_map - map that maintains all combinations
 * @ tracking - map used to track elements
*/
void get_possible_combinations_for_sum(stnode *h, int check_sum, vector<int> &main_map, vector<int> &tracking)
{
  if(!h)
    return;

  get_sum_path(h, check_sum, 0, main_map, tracking);
  get_possible_combinations_for_sum(h->l, check_sum, main_map, tracking);
  get_possible_combinations_for_sum(h->r, check_sum, main_map, tracking);
}
int main()
{
  stnode *pstHead = NULL;
  int count = 0;  

  pstHead = binarytree_createnode(50);

  pstHead->l = binarytree_createnode(20);
  pstHead->l->l = binarytree_createnode(10);
  pstHead->l->r = binarytree_createnode(30);


  pstHead->r = binarytree_createnode(10);
  pstHead->r->l = binarytree_createnode(10);
  pstHead->r->r = binarytree_createnode(5);
  pstHead->r->r->l = binarytree_createnode(5);

  /*
         50
        /  \
      20   10
     / \   / \
   10  30 10  5
               \
                5
 
  */
  vector<int> paths_with_root;
  get_possible_combinations_for_sum_always_with_root(pstHead, 70, paths_with_root);

  cout<<"ALL COMBINATIONS FROM ROOT ALWAYS ARE: " <<endl;
  for (vector<int>::iterator it = paths_with_root.begin(); it != paths_with_root.end(); it++)
  {
    if (*it == SEPRATOR)
      cout<<endl;
    else
      cout << *it << '\t';
  }

  cout <<endl<<endl;


  pstHead->r = binarytree_createnode(40);
  pstHead->r->l = binarytree_createnode(10);
  pstHead->r->r = binarytree_createnode(30);
  pstHead->r->l->l = binarytree_createnode(20);
 
/*
         50
        /  \
      20   40
     / \   / \
   10  30 10  30
          /
         20
 
*/

  vector<int> paths, tracking;
  get_possible_combinations_for_sum(pstHead, 70, paths, tracking);

  cout<<"ALL COMBINATIONS : " <<endl;
  for (vector<int>::iterator it = paths.begin(); it != paths.end(); it++)
  {
    if (*it == SEPRATOR)
      cout<<endl;
    else
      cout << *it << '\t';
  }

  printf("ALL DONE \n");
  
  return 0;
}


