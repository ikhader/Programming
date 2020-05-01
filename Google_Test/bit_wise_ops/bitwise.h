#ifndef __BITWISE_OPS__
#define __BITWISE_OPS__

#define SET_BIT_ZERO_BASED(v, pos) (v |=  1 << pos)
#define RESET_BIT_ZERO_BASED(v, pos) (v &=  ~(1 << pos))
#define FLIP_BIT_ZERO_BASED(v, pos) (v ^= (1 << pos))
#define SET_BITS_TILL_INDEX(v, ind) (v |= ((1 << ind) - 1))
#define IS_BIT_SET(v, pos) (v & (1<<pos))

void bitwise_get_set_bit_cnt(int n, int &cnt);

#endif// __BITWISE_OPS__
