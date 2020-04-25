

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


TEST(list_to_interger_head_last, Negative){
  int array[] =   {0, 1, 2, 3, 4};
  int array_2[] = {5, 4, 3, 2, 1, 0};
  stNode *h1 = NULL, *h2 = NULL;
  //adding nodes to list 
  for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
  {
    EXPECT_TRUE(add_node(&h1, array[i]));
  }
  int val;
  list_to_interger_head_last(h1, val);
  EXPECT_EQ(val, 43210);

  
  for(int i = 0; i < sizeof(array_2)/sizeof(array_2[0]); i++)
  {
    EXPECT_TRUE(add_node(&h2, array_2[i]));
  }
  list_to_interger_head_last(h2, val);
  EXPECT_EQ(val, 12345);

  val = 0;
  list_add_data_from_list_head_last(h1, h2, val);
  EXPECT_EQ(val, 55555);


//Head first examples
  val = 0;
  list_to_interger_head_first(h1, val);
  EXPECT_EQ(val, 1234);

  val = 0;
  list_to_interger_head_first(h2, val);
  EXPECT_EQ(val, 543210);

  val = 0;
  list_add_data_from_list_head_first(h1, h2, val);
  EXPECT_EQ(val, 544444);


  EXPECT_TRUE(delete_list(&h1));
  EXPECT_TRUE(delete_list(&h2));



}

}

