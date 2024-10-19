class Solution {

    int turn (int x) {
        size_t newInt = 0;

        while (x) {
            newInt = (newInt * 10) + (x % 10);
            x = x/10;
        }

        return newInt;
    }
public:
    bool isPalindrome(int x) {
        int NewInt = turn(x);

        if (NewInt == x && x >= 0)
            return true;
        return false;
    }
};