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
  stNode *prev, *next, *current;
  
  prev = next = NULL;
  current = *h;

  while(current)
  {
    next = current->n;
    current->n = prev;
    prev = current;
    current = next;
  }
  *h = prev;
  return true;
  
}

/*
Convert list into a sequence number.
Ex: 
i/p: 0 -> 1 -> 2 -> 3 -> 4 
o/p: 43210
Assumptions: data MUST be less be 10
*/

bool list_to_interger_head_last(stNode *h, int &res)
{
  int mul_fact = 1;
  res = 0;
  while(h)
  {
    if(h->data > 10) return false;
    res = res + (h->data * mul_fact);
    //cout<<"@@@@ List: " << h->data << " res: " << res <<endl;
    mul_fact = mul_fact * 10;
    h = h->n;
  }
  return true;

}

bool list_add_data_from_list_head_last(stNode* l1, stNode *l2, int &res)
{
  int num1, num2;
  num1 = num2 = res = 0;
  list_to_interger_head_last(l1, num1);
  list_to_interger_head_last(l2, num2);
  //cout <<"@@@@@ List1 " << num1 << " List2 : " <<num2 <<endl;
  res = num1 + num2;
}

/*
Convert list into a sequence number.
Ex: 
i/p: 1 -> 2 -> 3 -> 4 -> 5
o/p: 12345
Assumptions: data MUST be less be 10
*/

bool list_to_interger_head_first(stNode *h, int &res)
{
  int mul_fact = 1;
  stNode *t = h;
  res = 0;
  while(h)
  {
    if(h->data > 10) return false;
    res = (res * mul_fact) + h->data;
    
    mul_fact = 10;
    
    //cout<<"@@@@ head_first: List: " << h->data << " res: " << res << " mul_fact: " << mul_fact << endl;
    h = h->n;
  }
  return true;

}
bool list_add_data_from_list_head_first(stNode* l1, stNode *l2, int &res)
{
  int num1, num2;
  num1 = num2 = res = 0;
  list_to_interger_head_first(l1, num1);
  list_to_interger_head_first(l2, num2);
  //cout <<"@@@@@ List1 " << num1 << " List2 : " <<num2 <<endl;
  res = num1 + num2;
}


int main_(int argc, char *argv[])
{
  int a[] = {10, 20, 30, 40, 50};
  int i = 0;
  vector<int> v;
  stNode *h = NULL;

  for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    add_node(&h, a[i]);
  }
  printf("@@@@ List before reverse: \n");
  v.clear();
  get_node_details(h, v);
  for(i = 0; i <v.size(); i++)
  {
    printf("v[%d] = %d \n" , i, v[i]);
  } 
  reverse_list(&h);
  
  printf("List after reverse: \n");
  v.clear();
  get_node_details(h, v);
  for(i = 0; i <v.size(); i++)
  {
    printf("v[%d] = %d \n" , i, v[i]);
  } 
  return 0;
  
}
