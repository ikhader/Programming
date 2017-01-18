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
 
  post order: 20 30 10 40 50 60 90
*/

typedef struct __node
{
  int data;
  struct __node *l;
  struct __node *r;
}stnode;

void get_post_order(stnode *h, vector<int> &post_order)
{
  if (!h)
  {
    return;
  }

  get_post_order(h->l, post_order);
  get_post_order(h->r, post_order);
  post_order.push_back(h->data);
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

  /*
         90
        /  \
      10   40
     / \   / \
   20  30 50  60
 
  post order: 20 30 10 40 50 60 90
  */
  
  cout<<"Actual post order : 20 30 10 40 50 60 90" <<endl;
  cout<<"Funct  post order : ";

  vector<int> post_order_vec;
  get_post_order(pstHead, post_order_vec);

  for (vector<int>::iterator it = post_order_vec.begin(); it != post_order_vec.end(); it++)
  {
    cout<<*it << " " ;
  }
  cout <<endl;
  cout<<"ALL DONE " <<endl;;
  
  return 0;
}


