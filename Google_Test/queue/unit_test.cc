

#include <limits.h>
#include "queue.h"
#include "gtest/gtest.h"
namespace {

TEST(queue_testing, testing_funcs_of_queue) {
  queue *q = new queue(10);
  int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  
  int i;
  for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    EXPECT_TRUE(q->EnQ(a[i]));
  }
  
  EXPECT_FALSE(q->EnQ(110));

  vector<int> v;
  q->get_q(v);
  for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    EXPECT_TRUE(v[i] == a[i]);
  }
  
  int ele;
  ele = q->DeQ();
  EXPECT_TRUE(v[0] == ele);
  ele = q->DeQ();
  EXPECT_TRUE(v[1] == ele);
  ele = q->DeQ();
  EXPECT_TRUE(v[2] == ele);

  v.clear();
  q->get_q(v);
  int j;
  for(i = 3, j = 0; i < sizeof(a)/sizeof(a[0]); i++, j++)
  {
    EXPECT_EQ(v[j], a[i]);
  }
  
  delete q;
}

}

