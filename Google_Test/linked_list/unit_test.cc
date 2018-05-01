

#include <limits.h>
#include "linked_list.h"
#include "gtest/gtest.h"

namespace {

TEST(create_node, Negative) {
  stNode * t = create_node(10);
  EXPECT_TRUE(t != NULL);
  delete t;

}

TEST(list_validation, all_logics_list_validation) {
  int array[] = {10, 20, 30, 40, 50};
  int i, j;
  stNode *h = NULL;
  //adding nodes to list 
  for(i = 0; i < sizeof(array)/sizeof(array[0]); i++)
  {
    EXPECT_TRUE(add_node(&h, array[i]));
  }

  //validating nodes added and their sequence 
  vector<int> v;
  get_node_details(h, v);
  for(i = 0; i < sizeof(array)/sizeof(array[0]); i++)
  {
    EXPECT_EQ(array[i], v[i]);
  }
  
  //validating size of linked of list
  EXPECT_EQ(sizeof(array)/sizeof(array[0]), get_total_nodes(h));

  //deleting head of the list & validating size  
  EXPECT_TRUE(delete_node_at_index(&h, 1));
  EXPECT_EQ(sizeof(array)/sizeof(array[0]) - 1, get_total_nodes(h));

  //after head deletion validating rest of nodes
  v.clear();
  get_node_details(h, v);
  for(i = 1, j = 0; i < sizeof(array)/sizeof(array[0]); i++, j++)
  {
    EXPECT_EQ(array[i], v[j]);
  }

  //deleting tail or last element of the list & validating size
  EXPECT_TRUE(delete_node_at_index(&h, 4));
  EXPECT_EQ(sizeof(array)/sizeof(array[0]) - 2, get_total_nodes(h));

  //validating elements to check if last & first elements are really gone
  v.clear();
  get_node_details(h, v);
  for(i = 1, j = 0; i < sizeof(array)/sizeof(array[0]) - 1; i++, j++)
  {
    EXPECT_EQ(array[i], v[j]);
  }
  
  //SHOULD NOT delete anything; since list length is 3
  EXPECT_FALSE(delete_node_at_index(&h, 4));

  //adding back last element - len: 4
  EXPECT_TRUE(add_node(&h, 50));

  //reveseing the entire list and validting size
  reverse_list(&h);
  EXPECT_EQ(sizeof(array)/sizeof(array[0]) - 1, get_total_nodes(h));

  //validating reversed list is good or not
  v.clear();
  get_node_details(h, v);
  for(i = 1, j = sizeof(array)/sizeof(array[0]) - 2; i < sizeof(array)/sizeof(array[0]) - 1; i++, j--)
  {
    EXPECT_EQ(array[i], v[j]);
  }

  
  EXPECT_TRUE(delete_list(&h));
}

}

