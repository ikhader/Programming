#include <iostream>
#include <map>

/*
 * this programme will print child name & its parent name
 * Usually used to find super boss in an origanization
 *
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

void print_parent_child_map(map<int, int> rmap)
{
  for(map<int, int>::iterator it = rmap.begin(); it != rmap.end(); it++)
    cout << it->first << " === " << it->second <<endl;
}

/*
 * get_parent_child_details
 *   @stnode root - head of btree
 *   @map<int, int> &relationship - map to maintain relation ship
 *   @int parent - parent of the the current node
 * Fills in details to relationship map & return void. Recurssion is used
*/
void get_parent_child_map(stnode *root, map<int, int> &relationship, int parent)
{
  if (root == NULL)
    return;

  relationship[root->data] = parent;

  get_parent_child_map(root->l, relationship, root->data);
  get_parent_child_map(root->r, relationship, root->data);
   
}

int main()
{
  int a[] = { 50, 20, 30, 10, 90, 60};
  stnode *pstHead = NULL;


  for( int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    binarytree_addnode(&pstHead, a[i]);
  }
  map<int, int> rmap;
  get_parent_child_map(pstHead, rmap, pstHead->data);
  print_parent_child_map(rmap);
}
