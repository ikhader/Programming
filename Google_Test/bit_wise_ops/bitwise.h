#ifndef __BITWISE_OPS__
#define __BITWISE_OPS__

#define SET_BIT_ZERO_BASED(v, pos) (v |=  1 << pos)
#define RESET_BIT_ZERO_BASED(v, pos) (v &=  ~(1 << pos))
#define FLIP_BIT_ZERO_BASED(v, pos) (v ^= (1 << pos))
#define SET_BITS_TILL_INDEX(v, ind) (v |= ((1 << ind) - 1))
#define IS_BIT_SET(v, pos) (v & (1<<pos - 1))

void bitwise_get_set_bit_cnt(int n, int &cnt);
void bitwise_copy_from_start_to_end(unsigned char &dst, unsigned char src, int spos, int epos);

#endif// __BITWISE_OPS__
