class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size() - 1;
        int strIndex = size;
        int length = 0;

        while (strIndex >= 0 && s[strIndex] == ' ')
            strIndex--;
        for (int i = strIndex; i > -1 && s[i] != ' '; i--)
            length++;

        return length;
    }
};