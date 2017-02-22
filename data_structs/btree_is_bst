#include <iostream>
#include <limits.h>
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

bool validate_bst(stnode *h, int min, int max)
{
  if(!h) return true;
  
  cout <<"verfying values: " << h->data << " Min:" << min << " Max: " << max <<endl;
  if (h->data < min || h->data > max)
    return false;
  return validate_bst(h->l, min, h->data) && validate_bst(h->r, h->data + 1, max);
}

bool is_bst(stnode *h)
{
  bool isbst = true;
  isbst = validate_bst(h, INT_MIN, INT_MAX);
  return isbst;
}
int main()
{
  stnode *pstHead = NULL;
  int count = 0;  

  pstHead = binarytree_createnode(50);

  pstHead->l = binarytree_createnode(40);
  pstHead->l->l = binarytree_createnode(10);
  pstHead->l->r = binarytree_createnode(45);


  pstHead->r = binarytree_createnode(70);
  pstHead->r->l = binarytree_createnode(60);
  pstHead->r->r = binarytree_createnode(75);

  /*
         50
        /  \
      40   70
     / \   / \
   10  45 60  
 
  */
  
  bool bst = is_bst(pstHead);
  cout<< "Binar tree is " << bst <<endl; 
  cout<<"ALL DONE " <<endl;;
  
  return 0;
}


