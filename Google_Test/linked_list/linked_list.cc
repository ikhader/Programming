#include <iostream>
#include "linked_list.h"


using namespace std;

stNode * create_node(int data)
{
  stNode *t = new stNode; 
  if( NULL == t)
    return NULL;
  t->data = data;
  t->n = NULL;
  return t;
}
bool add_node(stNode **h, stNode *tNode)
{
  stNode *tHead = *h;
  if (NULL == tNode)
  {
    return false;
  }

  if(*h == NULL)
  {
    *h = tNode;
    return true;
  }

  while(tHead->n)
  {
    tHead = tHead->n;
  }
  tHead->n = tNode;
  return true;
}
bool add_node(stNode **h, int data)
{
  stNode *tNode = create_node(data);
  return add_node(h, tNode);
}

bool get_node_details(stNode *h, vector<int> &dets)
{
  if (NULL == h)
    return false;
  
  while(h)
  {
    dets.push_back(h->data);
    h = h->n;
  }
  
  return true;

}

bool delete_list(stNode **h)
{
  if(NULL == *h)
    return false;

  stNode *head = *h;

  while(head)
  {
    stNode *temp = head->n;
    delete head;
    head = temp;
  }  
  *h = NULL;
  return true;
}

int get_total_nodes(stNode *h)
{
  int cnt = 0;
  while(h)
  {
    cnt++;
    h = h->n;
  }
  return cnt;
}

bool delete_node_at_index(stNode **h, int index)
{
  int cnt = get_total_nodes(*h);

  if(index > cnt)
    return false;

  stNode *temp_head = *h;
  if(index == 1)// delete head
  {
    *h = temp_head->n;
    delete temp_head;
    return true;
  }  

  //stand one node before the node to be deleted
  while(index > 2)
  {
    temp_head = temp_head->n;
    index--;
  }
  
  delete temp_head->n;
  temp_head->n = NULL;
  return true;
}

bool reverse_list(stNode **h)
{
  if(NULL == *h)
    return false;

  stNode *t1, *t2, *t3;
  t1 = *h;
  t2 = t1->n;
  t1->n = NULL;
  t3 = t2->n;
  while(t1->n)
  {
    t2->n = t1;
    t1 = t2;
    t2 = t3;
    if(NULL != t3)
      t3 = t3->n;
  }
  *h = t1;
  return true;
}

int main(int argc, char *argv[])
{
  int a[] = {10, 20, 30, 40, 50};
  int i = 0;
  vector<int> v;
  stNode *h = NULL;

  for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    add_node(&h, a[i]);
  }
  reverse_list(&h);
  
}
