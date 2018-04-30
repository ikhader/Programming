

#include <limits.h>
#include "linked_list.h"
#include "gtest/gtest.h"

namespace {

TEST(create_node, Negative) {
  stNode * t = create_node(10);
  EXPECT_TRUE(t != NULL);
  delete t;

}

TEST(add_node, Negative) {
  int array[] = {10, 20, 30, 40, 50};
  int i, j;
  stNode *h = NULL;
  for(i = 0; i < sizeof(array)/sizeof(array[0]); i++)
  {
    EXPECT_TRUE(add_node(&h, array[i]));
  }

  vector<int> v;
  get_node_details(h, v);
  for(i = 0; i < sizeof(array)/sizeof(array[0]); i++)
  {
    EXPECT_EQ(array[i], v[i]);
  }
  
  EXPECT_EQ(sizeof(array)/sizeof(array[0]), get_total_nodes(h));
  
  EXPECT_TRUE(delete_node_at_index(&h, 1));
  EXPECT_EQ(sizeof(array)/sizeof(array[0]) - 1, get_total_nodes(h));
  v.clear();
  get_node_details(h, v);
  for(i = 1, j = 0; i < sizeof(array)/sizeof(array[0]); i++, j++)
  {
    EXPECT_EQ(array[i], v[j]);
  }

  EXPECT_TRUE(delete_node_at_index(&h, 4));
  EXPECT_EQ(sizeof(array)/sizeof(array[0]) - 2, get_total_nodes(h));
  v.clear();
  get_node_details(h, v);
  for(i = 1, j = 0; i < sizeof(array)/sizeof(array[0]) - 1; i++, j++)
  {
    EXPECT_EQ(array[i], v[j]);
  }
  
  EXPECT_FALSE(delete_node_at_index(&h, 4));

  EXPECT_TRUE(add_node(&h, 50));
  reverse_list(&h);
  EXPECT_EQ(sizeof(array)/sizeof(array[0]) - 1, get_total_nodes(h));
/*
  printf("reversing the list: %d \n", h->data);
  v.clear();
  get_node_details(h, v);
  for(j = 0; j < v.size(); j++)
    printf("HERE YOU GO:: %d \n", v[j]);
  for(i = 1, j = sizeof(array)/sizeof(array[0]) - 1; i < sizeof(array)/sizeof(array[0]) - 1; i++, j--)
  {
    printf("array[%d] = %d; v[%d] = %d \n", i, array[i], j, v[j]);
    EXPECT_EQ(array[i], v[j]);
  }

  */
  
  EXPECT_TRUE(delete_list(&h));
}

}

