#ifndef __BTREE__
#define __BTREE__
#include <iostream>
#include <vector>
#include <map>
#include <list>

#define SEPERATOR '|'

using namespace std;
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
stnode *btree_create_dummy_list3();

void btree_get_pre_order(stnode *h,std::vector<int> &res);
void btree_get_in_order(stnode *h, std::vector<int> &res);
void btree_get_in_order(stnode *h, std::vector<int> &res);
void btree_get_level_order(stnode *h, std::vector<int> &res, char sep = SEPERATOR);
void btree_get_level_order(stnode *h, vector<stnode *> &res, stnode *sep);
void btree_get_right_view(stnode *h, vector<int> &res);
void btree_get_left_view(stnode *h, vector<int> &res);
void btree_get_parent_child_map(stnode *h, stnode *parent, map<stnode *, stnode*> &parent_child_map);
void btree_get_only_leaf_nodes(stnode *h, vector<stnode*>&v);

void btree_list_breadth_nodes(stnode *h, list<int> &v, char sep = SEPERATOR);
#endif // __BTREE__


