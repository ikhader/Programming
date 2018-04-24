#ifndef __BTREE__
#define __BTREE__
#include <iostream>
#include <vector>

#define SEPERATOR '|'

typedef struct _stnode
{
  _stnode *l;
  _stnode *r;
  int data;
}stnode;

stnode * btree_create_node(int data);
bool btree_delete_tree(stnode *h);
bool insert_node(stnode *);
bool insert_node(int data);
int btree_get_min(stnode *h);
int btree_get_max(stnode *h);
int btree_get_sum_of_all_nodes(stnode *h);

stnode *btree_create_dummy_list2();
stnode *btree_create_dummy_list1();

void btree_get_pre_order(stnode *h,std::vector<int> &res);
void btree_get_in_order(stnode *h, std::vector<int> &res);
void btree_get_in_order(stnode *h, std::vector<int> &res);
void btree_get_level_order(stnode *h, std::vector<int> &res, char sep);
#endif // __BTREE__


