#include <iostream>
#include <queue>
#include <stdio.h>
#include <malloc.h>

using namespace std;

/*
         90
        /  \
      10   40
     / \   / \
   20  30 50  60
 
  srch seq: 90 10 40 20 30 50 60 
*/

typedef struct __node
{
  int data;
  struct __node *l;
  struct __node *r;
}stnode;

void breadth_first_srch(stnode *h,int ele, bool &isfound, int &loopcnt ) 
{
  if (!h)
    return ;

  loopcnt = 0 ;

  queue<stnode *> Q;
  Q.push(h);

  bool bDone = false;
  while(!bDone)
  {
    loopcnt++;
    if (0 == Q.size())
    {
      bDone = true;
      continue;
    }
    stnode *t = Q.front(); 
    cout << "Working on: " << t->data <<endl;
    Q.pop(); 
    if (t->data == ele)
    {
      bDone = true;
      isfound = true;
      continue;
    }
    if(t->l) Q.push(t->l);
    if(t->r) Q.push(t->r);
  }
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

  bool isfound = false;
  int loopcnt = 0;
  int val = 100;
  breadth_first_srch(pstHead, val, isfound, loopcnt);
  cout<< "Expected: 0 == Actual: " << isfound << " Loop: " <<loopcnt << " for val: " << val  <<endl<<endl<<endl;

  loopcnt = 0;
  isfound = false;
  val = 10;
  breadth_first_srch(pstHead, val, isfound, loopcnt);
  cout<< "Expected: 1 == Actual: " << isfound << " Loop: " <<loopcnt <<  " for val: " << val  <<endl<<endl<<endl;

  loopcnt = 0;
  isfound = false;
  val = 90;
  breadth_first_srch(pstHead, val, isfound, loopcnt);
  cout<< "Expected: 1 == Actual: " << isfound << " Loop: " <<loopcnt <<" for val: " << val  << endl<<endl<<endl;

  loopcnt = 0;
  isfound = false;
  val = 30;
  breadth_first_srch(pstHead, val, isfound, loopcnt);
  cout<< "Expected: 1 == Actual: " << isfound << " Loop: " <<loopcnt <<" for val: " << val  <<endl<<endl<<endl;

  loopcnt = 0;
  isfound = false;
  val = 60;
  breadth_first_srch(pstHead, val, isfound, loopcnt);
  cout<< "Expected: 1 == Actual: " << isfound << " Loop: " <<loopcnt <<" for val: " << val  <<endl<<endl<<endl;

  cout<<"ALL DONE " <<endl;;
  
  return 0;
}


