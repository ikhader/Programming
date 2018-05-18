

#include <limits.h>
#include "array.h"
#include "gtest/gtest.h"
namespace {

TEST(rotate_matrix, Negative) {
  int a[] = {1,2,3,4,5};
  int a_1[] = {2,3,4,5,1};
  int a_2[] = {3,4,5,1, 2};
  int i;

  rotate_matrix(a,1, sizeof(a)/sizeof(a[0]));
  for(i = 0; i < 5; i++)
  {
    EXPECT_TRUE(a[i] == a_1[i]);
  }
  
  rotate_matrix(a,1, sizeof(a)/sizeof(a[0]));
  for(i = 0; i < 5; i++)
  {
    EXPECT_TRUE(a[i] == a_2[i]);
  }
}

TEST(even_odd_seperation, Negative) {
  int a[] = {1,2,3,4,5};
  int a_result[] = {1,3,5,4,2};
  int i;

  even_odd_sepeartion(a, sizeof(a)/sizeof(a[0]));
  for(i = 0; i < 5; i++)
  {
    EXPECT_EQ(a_result[i], a[i]);
  }

  int a_1[] = {2,2,3,4,5};
  int a_1_result[] = {3,5,2,4,2};
  even_odd_sepeartion(a_1, sizeof(a_1)/sizeof(a_1[0]));
  for(i = 0; i < 5; i++)
  {
    EXPECT_EQ(a_1_result[i], a_1[i]);
  }

  int a_2[] = {2,2,6,4,5};
  int a_2_result[] = {5,2,6,4,2};
  even_odd_sepeartion(a_2, sizeof(a_2)/sizeof(a_2[0]));
  for(i = 0; i < 5; i++)
  {
    EXPECT_EQ(a_2_result[i], a_2[i]);
  }

  int a_3[] = {1,2,3,7,5};
  int a_3_result[] = {1,3,7,5,2};
  even_odd_sepeartion(a_3, sizeof(a_3)/sizeof(a_3[0]));
  for(i = 0; i < 5; i++)
  {
    EXPECT_EQ(a_3_result[i], a_3[i]);
  }
}
TEST(get_max_sum_path, Negative) 
{
  int a_1[] = {1, 2, 3, -4, 5, 123, 125};
  int start , end;
  start = end = 0;
  get_max_sum_path(a_1, sizeof(a_1)/sizeof(a_1[0]), &start, &end);
  EXPECT_EQ(start, 4);
  EXPECT_EQ(end, 6);

  int a_2[] = {1, 2, 3, -4, 5, 123, -125};
  start = end = 0;
  get_max_sum_path(a_2, sizeof(a_2)/sizeof(a_2[0]), &start, &end);
  EXPECT_EQ(start, 4);
  EXPECT_EQ(end, 5);

  int a_3[] = {1, 2, 3, -4, 5, -123, 225};
  start = end = 0;
  get_max_sum_path(a_3, sizeof(a_3)/sizeof(a_3[0]), &start, &end);
  EXPECT_EQ(start, 6);
  EXPECT_EQ(end, 6);

  int a_4[] = {1000, -2, 3, -4, 5, -123, 225};
  start = end = 0;
  get_max_sum_path(a_4, sizeof(a_4)/sizeof(a_4[0]), &start, &end);
  EXPECT_EQ(start, 0);
  EXPECT_EQ(end, 0);
}
}

