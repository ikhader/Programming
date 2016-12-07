#include <iostream>
#include <stdlib.h>
#include <vector>

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
 *Print top view of the binary tree
 * arguments: head -> head of binary tree
 * return: integer Vector with top view elements in it
 * Algo: push all the elements on left side
 *       push head
 *       push all the elements on the right side
 * Ex:       50
 *       20       90
 *     10   30  60
 *Output: 20 10 50 90
*/
vector<int> btree_get_top_view(stnode *h)
{
  vector<int> top_view_elements;
  cout <<"btree_get_top_view -- start" <<endl;
  if(!h)
  {
    cout <<"Tree is empty; nothing to do" << endl;
    return top_view_elements;
  }

  stnode *t = h->l;
  while(t)
  {
    top_view_elements.push_back(t->data);
    t = t->l;
  }

  top_view_elements.push_back(h->data);

  t = h->r;
  while(t)
  {
    top_view_elements.push_back(t->data);
    t = t->r;
  }
  return top_view_elements;
}

int main()
{
  int a[] = { 50, 20, 30, 10, 90, 60};
  int i ;
  int *p = (int *) malloc(sizeof(int) * sizeof(a)/sizeof(a[0]));
  stnode *pstHead = NULL;

  for( i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    binarytree_addnode(&pstHead, a[i]);
  }
  vector<int> det = btree_get_top_view(pstHead);

  for (vector<int>::iterator it = det.begin(); it != det.end(); it++)
    cout <<*it <<" ";
  cout <<endl;
}

