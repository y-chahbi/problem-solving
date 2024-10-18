class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse = 0;

        int size = 32;

        int i = 0;
        while (i++ < 32) {
            reverse <<= 1;
            reverse |= (n & 1);
            n >>= 1;
        }

        return reverse;
    }
};