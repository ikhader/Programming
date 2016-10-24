#include <iostream>
#include <queue>

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
  cout << "ptr is: " << p <<" value: " << data << endl;
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
 *50
 *20      90
 *10  30  60
 *
 * Algo: 
 * 1. assuming root not null, push this into Q. + NEW LINE
 * 2. start loop
 *    pop --> check if this has left/right, if so push into queue
 *    pop --> check if this NEWline -->print new line; if Qsize is greater than one, add NEWLINE
 *
 * */
void print_level_order(stnode *root)
{
  if (!root)
    return;
  
  void *New_line = 0x00;
  queue <stnode *> Q;

  stnode * t = root;

  Q.push(t);
  Q.push((stnode*)New_line);

  bool bDone = false;
  while (!bDone)
  {
    if (!Q.size())
    {
       bDone = true;
       continue;
    }

    t = Q.front();
    if(t->l)
      Q.push(t->l);
   
    if(t->r)
      Q.push(t->r);

    Q.pop();
    cout << t->data << " ";

    //check for new line
    if ( Q.front() == New_line)
    {
      cout<<endl;
      Q.pop();
      if (Q.size())
        Q.push((stnode*)New_line);
    }
  }
  
}

int main()
{
  int a[] = { 50, 20, 30, 10, 90, 60};
  stnode *pstHead = NULL;


  for( int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    binarytree_addnode(&pstHead, a[i]);
  }
  print_level_order(pstHead);
  cout <<"ALL DONE" <<endl;
}

