
#include <iostream>
#include <queue>
#include <stdlib.h>

#include "btree.h"

//#define __debug__ 1

using namespace std;

/*
      100   
     /    \   
    200   -200  
   / \   /  \
  -5 -4 -3  -2 
    /  \      \
  -401 -402    -202
              

*/
stnode *btree_create_dummy_list3()
{
  stnode *t = btree_create_node(100);

  t->l = btree_create_node(200);
  t->r = btree_create_node(-200);

  t->l->l = btree_create_node(-5);
  t->l->r = btree_create_node(-4);

  t->r->l = btree_create_node(-3);
  t->r->r = btree_create_node(-2);
  
  t->l->r->l = btree_create_node(-401);
  t->l->r->r = btree_create_node(-402);

  t->r->r->r = btree_create_node(-202);
  return t;
}

/*
       0
     /    \
    1     -1
   / \   /  \
  -5 -4 -3  -2
          

*/
stnode *btree_create_dummy_list2()
{
  stnode *t = btree_create_node(0);

  t->l = btree_create_node(1);
  t->r = btree_create_node(-1);

  t->l->l = btree_create_node(-5);
  t->l->r = btree_create_node(-4);

  t->r->l = btree_create_node(-3);
  t->r->r = btree_create_node(-2);
  
  return t;
}


/*
       50
     /    \
    30    80
   / \   /  \
  15 40 60  90
          

*/
stnode *btree_create_dummy_list1()
{
  stnode *t = btree_create_node(50);

  t->l = btree_create_node(30);
  t->r = btree_create_node(80);

  t->l->l = btree_create_node(15);
  t->l->r = btree_create_node(40);

  t->r->l = btree_create_node(60);
  t->r->r = btree_create_node(90);
  
  return t;
}


stnode * btree_create_node(int data)
{
  stnode *t = (stnode*)malloc(sizeof(stnode));
  if ( NULL == t)
  {
    cout<<"Error in memory allocation "<<endl;
    return NULL;
  }

  t->data = data;
  t->l = t->r = NULL;
  return t;
}

// lets not worry for testing
bool insert_node(stnode *)
{
  return false;
}

// lets not worry for testing
bool insert_node(int data)
{
  return false;
}

bool btree_delete_tree(stnode *h)
{
  if (NULL == h)
    return false;

  queue<stnode*>q;
  q.push(h);
  
  while(q.size() != 0)
  {
    stnode *t = q.front();
#ifdef __debug__
    cout <<"Delete: "<< t->data << endl;
#endif //__debug__

    q.pop();
    if (t->l) q.push(t->l);
    if (t->r) q.push(t->r);


    delete t;
  }
  
  return true;
  
}

int btree_get_sum_of_all_nodes(stnode *h)
{
  if ( NULL == h)
    return 0;

  return h->data + btree_get_sum_of_all_nodes(h->l) + btree_get_sum_of_all_nodes(h->r);
}

void btree_get_pre_order(stnode *h, vector<int> &res)
{
  if( NULL == h)
    return;
  
  res.push_back(h->data);
  btree_get_pre_order(h->l, res);  
  btree_get_pre_order(h->r, res);  

}

void btree_get_in_order(stnode *h, vector<int> &res)
{
  if( NULL == h)
    return;
  
  btree_get_in_order(h->l, res);  
  res.push_back(h->data);
  btree_get_in_order(h->r, res);  

}

void btree_get_post_order(stnode *h, vector<int> &res)
{
  if( NULL == h)
    return;
  
  btree_get_post_order(h->l, res);  
  btree_get_post_order(h->r, res);  
  res.push_back(h->data);

}

void btree_get_level_order(stnode *h, vector<int> &res, char sep)
{
  if (NULL == h)
    return;

  queue<stnode*> Q;

  res.push_back(h->data);
  res.push_back(sep);

  stnode *tnode = btree_create_node(sep);
  Q.push(h);
  Q.push(tnode);

  while(Q.size() != 0)
  {
    
    stnode *front_node = Q.front();
    Q.pop();
    while(front_node != tnode)
    {
      if(front_node->l) 
      {
        Q.push(front_node->l);
        res.push_back(front_node->l->data);
      }
      if(front_node->r) 
      {
        Q.push(front_node->r);
        res.push_back(front_node->r->data);
      }
      front_node = Q.front();
      Q.pop();
    }
    
    if(0 != Q.size())
    {
      Q.push(tnode);
      res.push_back(sep);
    }
  }
  
  
  free(tnode);
}


void btree_get_level_order(stnode *h, vector<stnode *> &res, stnode *sep)
{
  if( NULL == h)
    return ;
  queue<stnode*> Q;

  //res.push_back(h);
  //res.push_back(sep);

  Q.push(h);
  Q.push(sep);

  while(Q.size() != 0)
  {
    stnode *f = Q.front();
    Q.pop();

    while(f != sep)
    {
      res.push_back(f);
      if(f->l) Q.push(f->l);
      if(f->r) Q.push(f->r);
      f = Q.front();
      Q.pop();
    }

    res.push_back(sep);
    if(Q.size() != 0)
      Q.push(sep);
    
  }
  
}

void btree_get_right_view(stnode *h, vector<int> &res)
{
  vector<int> level_order;
  btree_get_level_order(h, level_order, SEPERATOR);
  
  for (int i = 0; i < level_order.size(); i++)
  {
    if(level_order[i] == SEPERATOR)
    {
      res.push_back(level_order[i-1]);
      cout <<"RIGHT Pushing back: " << res[i-1] <<endl;

    }
  }
}


void btree_get_left_view(stnode *h, vector<int> &res)
{
  vector<int> level_order;
  btree_get_level_order(h, level_order);

  res.push_back(level_order[0]);
  for (int i = 1; i < level_order.size(); i++)
  {
    if(level_order[i] == SEPERATOR && i+1 < level_order.size())
    {
      res.push_back(level_order[i+1]);
      //cout <<"LEFT Pushing back: " << res[i+1] <<endl;
    }
  }
}
int btree_get_max(stnode *h)
{
  return 0;
}

int btree_get_min(stnode *h)
{
  return 0;
}

void btree_get_parent_child_map(stnode *h, stnode *parent, map<stnode *, stnode*> &parent_child_map)
{
  if( NULL == h)
    return;

  parent_child_map[h] = parent;
  btree_get_parent_child_map(h->l, h, parent_child_map);
  btree_get_parent_child_map(h->r, h, parent_child_map);
}


void btree_get_only_leaf_nodes(stnode *h, vector<stnode*>&v)
{
  if(NULL == h)
    return;

  if(h->r == NULL && h->l == NULL)
    v.push_back(h);

 btree_get_only_leaf_nodes(h->l, v);
 btree_get_only_leaf_nodes(h->r, v);

}
