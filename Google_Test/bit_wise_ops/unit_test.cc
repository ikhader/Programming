


#include "bitwise.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

namespace {

TEST(SET_BIT_ZERO_BASED, Postivie) {
  char c = 1;
  
  SET_BIT_ZERO_BASED(c, 1);
  EXPECT_TRUE(c == 3);

  SET_BIT_ZERO_BASED(c, 2);
  EXPECT_TRUE(c == 7);

  SET_BIT_ZERO_BASED(c, 3);
  EXPECT_TRUE(c == 15);

  int i = 128;
  SET_BIT_ZERO_BASED(i, 0);
  EXPECT_TRUE(i == 129);

  SET_BIT_ZERO_BASED(i, 0);
  EXPECT_TRUE(i == 129);

  SET_BIT_ZERO_BASED(i, 1);
  EXPECT_TRUE(i == 131);

  SET_BIT_ZERO_BASED(i, 2);
  EXPECT_TRUE(i == 135);


}
TEST(RESET_BIT_ZERO_BASED, Postivie) {
  char c = 15;

  RESET_BIT_ZERO_BASED(c, 3);
  EXPECT_TRUE(c == 7);
  
  RESET_BIT_ZERO_BASED(c, 3);
  EXPECT_TRUE(c == 7);

  RESET_BIT_ZERO_BASED(c, 2);
  EXPECT_TRUE(c == 3);
}

TEST(SET_BITS_TILL_INDEX, Postivie) {
  int c = 64;
  SET_BITS_TILL_INDEX(c, 2);
  EXPECT_TRUE(c == 67);

  SET_BITS_TILL_INDEX(c, 3);
  EXPECT_TRUE(c == 71);

  SET_BITS_TILL_INDEX(c, 4);
  EXPECT_TRUE(c == 79);
}

TEST(FLIP_BIT_ZERO_BASED, Postivie) {
  int c = 1;
  FLIP_BIT_ZERO_BASED(c, 0);
  EXPECT_TRUE(c == 0);

  FLIP_BIT_ZERO_BASED(c, 0);
  EXPECT_TRUE(c == 1);

}

TEST(bitwise_get_set_bit_cnt, Postivie) {
  int i = 128;
  int cnt = 0;

  bitwise_get_set_bit_cnt(i, cnt);
  EXPECT_TRUE(cnt == 1);

  cnt = 0;
  SET_BIT_ZERO_BASED(i, 0);
  EXPECT_TRUE(i == 129);
  bitwise_get_set_bit_cnt(i, cnt);
  EXPECT_TRUE(cnt == 2);

  i = 127;
  cnt = 0;
  SET_BIT_ZERO_BASED(i, 0);
  EXPECT_TRUE(i == 127);
  bitwise_get_set_bit_cnt(i, cnt);
  EXPECT_TRUE(cnt == 7);

  RESET_BIT_ZERO_BASED(i, 0);
  EXPECT_TRUE(i == 126);
  bitwise_get_set_bit_cnt(i, cnt);
  EXPECT_TRUE(cnt == 6);
}

/*
1101 0000
*/
TEST(bitwise_copy_from_start_to_end, Positive){
  unsigned char dst = 128;
  unsigned char src = 85;

  bitwise_copy_from_start_to_end(dst, src, 4, 7);
  //cout <<"@@@ dst is: " << dst <<endl;
  //printf("\n\n dst: %d \n\n", dst);
  EXPECT_TRUE(dst == 208);
}

TEST(flip_nibble, Positive){
  unsigned char s1 = 15;
  flip_nibble(s1);
  printf("NEXT ROUNT\n");
  flip_nibble(s1);
}

}

