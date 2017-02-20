#include <iostream>
#include <vector>
#include <list>
#include <queue>


using namespace std;

/*
 *   Input Tree:
 *           10
 *          /  \
 *         2     15
 *       /  \   /  \
 *      10  28  5  20
 *      /       /   \
 *      8      25   10
 * 
 *  output:
 *  10
 *  2 15
 *  10 28 5 20
 *  8 25 10
 *
 *
*/


typedef struct _stnode
{
  int d;
  _stnode *l;
  _stnode *r;
}stnode;

stnode* create_node(int a)
{
  stnode *p = new stnode();
  p->d = a;
  p->l = p->r = NULL;
  return p;
}

#define DELIMETTER ((stnode*)0X10)

/*
 * This routine will create list of vectors that will be level ordered 
 * Logic: 1. Copy each element into Q
 *        2. Dequeue and Check if this element is delimitter, if so break 
 *        3. Otherwise check if left/right exists push back into Q
 *        4. Push this element in newly created list
 *        5. keep doing this step untill Q size becomes ZERO
 *
*/
void create_list_with_breadth(stnode *h, vector< list<int> * > &output)
{
  if (NULL == h)
    return;

  queue <stnode*> Q;
  Q.push(h);
  Q.push(DELIMETTER);

  bool bDone = false;
  while(!bDone)
  {
    list<int> *l = new list<int>; 
    while(1)
    {
      stnode *t = Q.front();   
      Q.pop();
      if (t == DELIMETTER)
        break;

      if(t->l) Q.push(t->l);
      if(t->r) Q.push(t->r);
      l->push_back(t->d);
    }

    output.push_back(l);
    if(0 == Q.size())
      bDone = true;
    else
      Q.push(DELIMETTER);
  }
}

int main(int argc, char *argv[])
{
  stnode *h = create_node(10);

  h->l = create_node(2);
  h->r = create_node(15);


  h->l->l = create_node(10);
  h->l->r = create_node(28);

  h->l->l->l = create_node(8);


  h->r->l = create_node(5);
  h->r->r = create_node(20);
  
  h->r->l->l = create_node(25);
  h->r->r->l = create_node(10);

  vector< list <int> * > result;
  
  
  create_list_with_breadth(h, result);

  for(vector< list<int>* >::iterator it = result.begin(); it != result.end(); it++)
  {
    list<int> *l = *it;
    for (list<int>::iterator l_it = l->begin(); l_it != l->end(); l_it++)
      cout << *l_it << " ";
    cout <<endl;
  }
  return -1;
}
