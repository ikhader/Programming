#include <iostream>
#include <vector>
#include <malloc.h>
using namespace std;

typedef struct __node
{
  int data;
  struct __node *l;
  struct __node *r;
}stnode;

void get_pre_order(stnode *h, vector<int> &t)
{
  if(!h)
    return;

  t.push_back(h->data);
  get_pre_order(h->l, t);
  get_pre_order(h->r, t);
}

bool check_if_btree_is_subtree(vector<int>main_tree, vector<int> subtree)
{
  if(main_tree.size() <= 0 || subtree.size() <= 0)
    return false;

  vector<int>::iterator tp_mt;
  int hits = 0;

  for(vector<int>::iterator mt = main_tree.begin(); mt != main_tree.end(); mt++)
  {
    tp_mt = mt;
    for(vector<int>::iterator st = subtree.begin(); st != subtree.end(); st++)
    {
      if(*st == *tp_mt)
      {
        //cout << "Match found: "<< *st << " " << *mt <<endl;
        tp_mt++;

        hits = hits + 1;
       
        if (hits == subtree.size())
          return true;
      }
      else
      {
        hits = 0;
        //cout<<"resetting because:  " << *st << " " << *tp_mt <<endl;
      }
    }
  }

  return false;
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
  stnode *tree1 = NULL, *tree2 = NULL;
  int count = 0;
/* tree 1
         90
        /  \
      10   40
     / \   / \
   20  30 50  60
 
  pre order: 90 10 20 30 40 50 60
*/

  tree1 = binarytree_createnode(90);
  tree1->l = binarytree_createnode(10);
  tree1->l->l = binarytree_createnode(20);
  tree1->l->r = binarytree_createnode(30);
  tree1->r = binarytree_createnode(40);
  tree1->r->l = binarytree_createnode(50);
  tree1->r->r = binarytree_createnode(60);

/*
    tree2
      10
     / \
    20 30

*/

  tree2 = binarytree_createnode(10);
  tree2->l = binarytree_createnode(20);
  tree2->r = binarytree_createnode(30);


  vector<int> preorder_tree1;
  vector<int> preorder_tree2;

  //Success case
  //cout<<"Actual post order : 90 10 20 30 40 50 60" <<endl;
  //cout<<"Funct  post order : ";

  get_pre_order(tree1, preorder_tree1);
  //for(vector<int>::iterator it = preorder_tree1.begin(); it != preorder_tree1.end(); it++)
    //cout << *it << " " ;  
  //cout <<endl<<endl;

  //cout<<"Actual post order : 10 20 30" <<endl;
  //cout<<"Funct  post order : ";

  get_pre_order(tree2, preorder_tree2);
  //for(vector<int>::iterator it = preorder_tree2.begin(); it != preorder_tree2.end(); it++)
  //  cout << *it << " " ;  
  //cout <<endl<<endl;
  
  bool isFound = check_if_btree_is_subtree(preorder_tree1, preorder_tree2);
  cout<<"Expected true; Actual: " << isFound <<endl;
  
  //failure case
  tree2->r->data = 40;
  preorder_tree2.clear();
  get_pre_order(tree2, preorder_tree2);

  isFound = check_if_btree_is_subtree(preorder_tree1, preorder_tree2);
  cout<<"Expected false; Actual: " << isFound <<endl;

  cout<<"ALL DONE " <<endl;;

  return 0;
}
