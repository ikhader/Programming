#include <limits.h>
#include "quick_find.h"
#include "gtest/gtest.h"

namespace
{
  TEST(quick_find, Constructor)
  {
    quick_find qf(20);
    qf.print_array();
    ASSERT_EQ(20, qf.get_size());

    quick_find qf_2;
    qf_2.print_array();
    ASSERT_EQ(5, qf_2.get_size());

    quick_find qf_3(0);
    qf_2.print_array();
    ASSERT_EQ(0, qf_3.get_size());
  }
}
