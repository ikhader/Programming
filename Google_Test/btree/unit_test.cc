
#include<iostream>
#include <limits.h>
#include "btree.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

namespace {

TEST(btree_create_node, create_delete_btree) {
  stnode *t = btree_create_node(10);
  EXPECT_TRUE(NULL != t);

  t->l = btree_create_node(20);
  t->r = btree_create_node(30);
  t->l->l = btree_create_node(40);
  t->l->r = btree_create_node(50);
  
  btree_delete_tree(t);

  stnode *t1 = btree_create_dummy_list1();
  btree_delete_tree(t1);

  t1 = btree_create_dummy_list2();
  btree_delete_tree(t1);
}


TEST(btree_get_sum_of_all_nodes, get_sum_nodes) 
{
  stnode *t1 = btree_create_dummy_list1();
  EXPECT_EQ(365, btree_get_sum_of_all_nodes(t1));
  btree_delete_tree(t1);

  stnode *t2 = btree_create_dummy_list2();
  EXPECT_EQ(-14, btree_get_sum_of_all_nodes(t2));
  btree_delete_tree(t2);

}

TEST(btree_pre_order, pre_order_testing)
{
  
  stnode *t = btree_create_dummy_list1();
  std::vector<int> v;

  int array_l1_pre_order[] = {50, 30, 15,40, 80, 60, 90};
  btree_get_pre_order(t, v);

  for(int idx = 0; idx < v.size(); idx++)
    EXPECT_EQ(array_l1_pre_order[idx], v[idx]);
  v.clear();

  int array_l1_in_order[] = {15, 30, 40, 50, 60, 80, 90};
  btree_get_in_order(t, v);
  for(int idx = 0; idx < v.size(); idx++)
    EXPECT_EQ(array_l1_in_order[idx], v[idx]);
  v.clear();

  int array_l1_level_order[] = {50, SEPERATOR, 30, 80, SEPERATOR, 15, 40, 60, 90, SEPERATOR};
  btree_get_level_order(t, v, SEPERATOR);
  for(int idx = 0; idx < v.size(); idx++)
  {
    EXPECT_EQ(array_l1_level_order[idx], v[idx]);
#ifdef __debug__
    cout<<"array [" << array_l1_level_order[idx] << "] fun_ret[" << v[idx] << "]" <<endl;
#endif //__debug__
  }
  v.clear();
  
  cout <<"@@@@@@@@@@@@@@@@@@@@@@" <<endl;
  
  list<int> l;
  btree_list_breadth_nodes(t, l, SEPERATOR);
  for(int idx = 0; idx < v.size(); idx++)
  {
    EXPECT_EQ(array_l1_level_order[idx], v[idx]);
#ifdef __debug__
    cout<<"array [" << array_l1_level_order[idx] << "] fun_ret[" << v[idx] << "]" <<endl;
#endif //__debug__
  }
  cout <<"@@@@@@@@@@@@@@@@@@@@@@" <<endl;
  v.clear();


  int array_l1_left_view[] = {50, 30, 15};
  btree_get_left_view(t, v);
  for(int idx = 0; idx < v.size(); idx++)
    EXPECT_EQ(array_l1_left_view[idx], v[idx]);
  v.clear();

  int array_l1_right_view[] = {50, 80, 90};
  btree_get_right_view(t, v);
  for(int idx = 0; idx < v.size(); idx++)
    EXPECT_EQ(array_l1_right_view[idx], v[idx]);
  v.clear();

  btree_delete_tree(t);
 //////////////////////////////////////////////////////////////////////////////
 ///////////////////for list l3 more complicated///////////////////////////////
 //////////////////////////////////////////////////////////////////////////////

  t = btree_create_dummy_list3();
  int array_l3_level_order[] = {100, SEPERATOR, 200, -200, SEPERATOR, -5, -4, -3, -2, SEPERATOR, -401, -402, -202, SEPERATOR};
  btree_get_level_order(t, v, SEPERATOR);
  for(int idx = 0; idx < v.size(); idx++)
  {
    EXPECT_EQ(array_l3_level_order[idx], v[idx]);
#ifdef __debug__
    cout<<"array [" << array_l1_level_order[idx] << "] fun_ret[" << v[idx] << "]" <<endl;
#endif //__debug__
  }
  v.clear();

  vector<stnode *> node_vector;
  btree_get_only_leaf_nodes(t, node_vector);
  
  EXPECT_EQ(node_vector.size(), 5);

  EXPECT_EQ(node_vector[0], t->l->l);
  EXPECT_EQ(node_vector[1], t->l->r->l);
  EXPECT_EQ(node_vector[2], t->l->r->r);

  EXPECT_EQ(node_vector[3], t->r->l);
  EXPECT_EQ(node_vector[4], t->r->r->r);

  btree_delete_tree(t);
}

TEST(btree_parent_child, parent_child_map)
{
  stnode * h = btree_create_dummy_list1();
  map<stnode *, stnode*> pc_map;
  
  btree_get_parent_child_map(h, NULL, pc_map);

  EXPECT_TRUE(pc_map[h] ==  NULL);

  EXPECT_TRUE(pc_map[h->l] ==  h);
  EXPECT_TRUE(pc_map[h->r] ==  h);
  
  EXPECT_TRUE(pc_map[h->l->r] ==  h->l);
  EXPECT_TRUE(pc_map[h->l->l] ==  h->l);
  
  EXPECT_TRUE(pc_map[h->r->r] ==  h->r);
  EXPECT_TRUE(pc_map[h->r->l] ==  h->r);

  pc_map.clear();

  //check for level order with stnode as reference
  vector<stnode*> v;
  stnode *sep = btree_create_node(SEPERATOR);
  btree_get_level_order(h, v, sep);
  
  EXPECT_TRUE(v[1] == sep);
  EXPECT_EQ(v[4], sep);
  EXPECT_EQ(v[9], sep);

  EXPECT_EQ(v[8], h->r->r);
  EXPECT_EQ(v[7], h->r->l);
  EXPECT_EQ(v[6], h->l->r);
  EXPECT_EQ(v[5], h->l->l);
  
  EXPECT_EQ(v[2], h->l);
  EXPECT_EQ(v[3], h->r);

  v.clear();
  btree_get_only_leaf_nodes(h, v);

  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], h->r->r);
  EXPECT_EQ(v[2], h->r->l);
  EXPECT_EQ(v[1], h->l->r);
  EXPECT_EQ(v[0], h->l->l);
  

  btree_delete_tree(h);
  btree_delete_tree(sep);
}
}
