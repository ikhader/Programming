
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

  btree_delete_tree(t);
}
}
