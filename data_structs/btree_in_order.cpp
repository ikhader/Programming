#include <iostream>
#include <vector>
#include <stdio.h>
#include <malloc.h>

using namespace std;

/*
         90
        /  \
      10   40
     / \   / \
   20  30 50  60
 
  in order: 20 10 30 90 50 40 60
*/

typedef struct __node
{
  int data;
  struct __node *l;
  struct __node *r;
}stnode;

void get_in_order(stnode *h, vector<int> &pre_order)
{
  if (!h)
  {
    return;
  }

  get_in_order(h->l, pre_order);
  pre_order.push_back(h->data);
  get_in_order(h->r, pre_order);
}

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

int main()
{
  stnode *pstHead = NULL;
  int count = 0;  

  pstHead = binarytree_createnode(90);

  pstHead->l = binarytree_createnode(10);
  pstHead->l->l = binarytree_createnode(20);
  pstHead->l->r = binarytree_createnode(30);


  pstHead->r = binarytree_createnode(40);
  pstHead->r->l = binarytree_createnode(50);
  pstHead->r->r = binarytree_createnode(60);

  cout<<"Actual in order : 20 10 30 90 50 40 60" <<endl;
  cout<<"Funct  in order : ";

  vector<int> pre_order_vec;
  get_in_order(pstHead, pre_order_vec);

  for (vector<int>::iterator it = pre_order_vec.begin(); it != pre_order_vec.end(); it++)
  {
    cout<<*it << " " ;
  }
  cout <<endl;
  cout<<"ALL DONE " <<endl;;
  
  return 0;
}


