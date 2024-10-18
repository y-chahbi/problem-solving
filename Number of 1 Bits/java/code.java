class Solution {
    public int hammingWeight(int n) {
        int size = 32;
        int counter = 0;

        int i = 0;
        while (i < size) {
            if ((n & 1) == 1) {
                counter++;
            }
            n = n >> 1;
            i++;
        }
        return counter;
    }
}
