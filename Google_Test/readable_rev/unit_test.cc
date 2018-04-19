

#include <limits.h>
#include "string_operations.h"
#include "gtest/gtest.h"

namespace {

TEST(xstrlen, custom_len) {
  char str[] = "hello";
  EXPECT_EQ(5, xstrlen(str));

  EXPECT_EQ(11, xstrlen("Hello world"));
  EXPECT_EQ(15, xstrlen("Hello#### world"));
}

TEST(xstrrev, test_case_1){
  char s1[] = "abc";
  EXPECT_STREQ("cba", xstrrev(s1));

  char s2[] = "abc xyz";
  EXPECT_STREQ("zyx cba", xstrrev(s2));
}

TEST(xstrrev, partial_rev){
  char s1[] = "abcdefg";
  EXPECT_STREQ("dcbaefg", xstrrev(s1, 4));

  char s2[] = "abc defg";
  EXPECT_STREQ(" cbadefg", xstrrev(s2, 4));
}

TEST(readable_reverse, partial_rev){
  char s1[] = "abcd";
  EXPECT_STREQ("dcba", readable_reverse(s1));

  char s2[] = "abcd wxyz";
  EXPECT_STREQ("wxyz abcd", readable_reverse(s2));

  char s3[] = "HELLO WORLD";
  EXPECT_STREQ("WORLD HELLO", readable_reverse(s3));

  
}

TEST(readable_reverse, special_chars)
{
  char s1[] = { 't', 'a', 'b', '\t', 't', 'e', 's', 't', '\0'};
  char *r1 = readable_reverse(s1);
  EXPECT_STREQ("test\ttab", r1);
}

}

