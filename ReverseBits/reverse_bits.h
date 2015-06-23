/*
 * Author : Jeremy Zhao
 * Email  : jqzhao@live.com
 * Date   : 2015/06/16
 *
 * Source : https://leetcode.com/problems/reverse-bits/
 * Problem:	Reverse Bits
 * Description: 
 *	Reverse bits of a given 32 bits unsigned integer.
 *
 * 	For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
 *	return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * 	Follow up:
 * 	If this function is called many times, how would you optimize it?
 *
 */
class Solution {
	public: 
		uint32_t reverseBits(uint32_t n) {
			int mark = 0x1;
			int bits = 31;
			uint32_t val = 0;
			int i;
			for (i = 0; i < 16; i++) {
				val |= (n & mark) << bits;
				mark <<= 1;
				bits -= 2;
			}

			bits = 1;
			for (i = 16; i < 32; i++) {
				val |= (n & mark) >> bits;
				mark <<= 1;
				bits += 2;
			}

			return val;
		}
};
