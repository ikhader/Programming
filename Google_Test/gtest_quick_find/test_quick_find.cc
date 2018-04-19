#include <limits.h>
#include "quick_find.h"
#include "gtest/gtest.h"

namespace
{
  TEST(quick_find, Constructor)
  {
    quick_find qf(20);
    ASSERT_EQ(20, qf.get_size());

    quick_find qf_2;
    ASSERT_EQ(5, qf_2.get_size());

    quick_find qf_3(0);
    ASSERT_EQ(0, qf_3.get_size());
  }

  TEST(quick_find, Negative)
  {
    quick_find qf(20);
    EXPECT_FALSE(qf.is_connected(0, 10));
    EXPECT_FALSE(qf.is_connected(0, 19));

    EXPECT_FALSE(qf.connect_nodes(0, 50));
  }
  
  TEST(quick_find, trippler_linkers)
  {
    quick_find qf(20);
    EXPECT_TRUE(qf.connect_nodes(0, 10));
    EXPECT_TRUE(qf.connect_nodes(0, 8));
    EXPECT_TRUE(qf.is_connected(10, 8));

    EXPECT_TRUE(qf.connect_nodes(1, 11));
    EXPECT_TRUE(qf.connect_nodes(1, 9));
    EXPECT_TRUE(qf.is_connected(11, 9));

    EXPECT_TRUE(qf.connect_nodes(1, 11));
    EXPECT_TRUE(qf.connect_nodes(1, 1));
    EXPECT_TRUE(qf.is_connected(1, 11));

  }

  TEST(quick_find, four_linkers)
  {
    quick_find qf(50);
    EXPECT_TRUE(qf.connect_nodes(0, 10));
    EXPECT_TRUE(qf.connect_nodes(0, 8));
    EXPECT_TRUE(qf.connect_nodes(8, 18));
    EXPECT_TRUE(qf.is_connected(10, 18));
    EXPECT_TRUE(qf.is_connected(0, 18));


    EXPECT_TRUE(qf.connect_nodes(1, 11));
    EXPECT_TRUE(qf.connect_nodes(2, 22));
    EXPECT_TRUE(qf.connect_nodes(3, 33));
    EXPECT_TRUE(qf.connect_nodes(4, 44));
    EXPECT_TRUE(qf.connect_nodes(1, 4));
    EXPECT_TRUE(qf.is_connected(11, 44));

  }
}
