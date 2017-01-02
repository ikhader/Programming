#include <iostream>

/*
 *  finds sum of all elements in binary tree
*/

using namespace std;

typedef struct __node
{
  int data;
  struct __node *l;
  struct __node *r;
}stnode;


stnode * binarytree_createnode(int data)
{
  stnode *pnode = new stnode();
  if(!pnode)
    return NULL;
  pnode->data = data;
  pnode->l = NULL;
  pnode->r = NULL;

  return pnode;
}

bool binarytree_addnode(stnode **pstHead, int data)
{
  stnode *t, *p ;
  bool badd = false;

  p = binarytree_createnode(data);
  if(!p)
    return false;
  if(*pstHead == NULL)
  {
    *pstHead = p;
    return true;
  }

  t = *pstHead;

  while (!badd)
  {
    if(t->data >= p->data)
    {
      if(t->l)
        t = t->l;
      else
      {
        t->l = p;
        badd = true;
      }
    }
    else
    {
      if(t->r)
        t = t->r;
      else
      {
        t->r = p;
        badd = true;
      }
    }

  }
  return true;
}

/*
 * get_parent_child_details
 *   @stnode root - head of btree
 *   @int *sum - stores sum of all elements
 * algo: Recussively calls each node & sums up each node
*/
void sum_of_all_elements(stnode *root, int *sum)
{
  if (root == NULL)
    return;
  *sum = *sum + root->data;
  sum_of_all_elements(root->l, sum);
  sum_of_all_elements(root->r, sum);
}

int main()
{
  int a[] = { 50, 20, 30, 10, 90, 60};
  stnode *pstHead = NULL;


  for( int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    binarytree_addnode(&pstHead, a[i]);
  }
  int sum = 0;
  sum_of_all_elements(pstHead, &sum);
  cout<<"Sum of all elements: " << sum << endl; 
}
