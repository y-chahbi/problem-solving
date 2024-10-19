class Solution {
    std::array<char, 3> Openparentheses{ '(', '{', '[' };
    std::array<char, 3> Closeparentheses{ ')', '}', ']' };

    bool isInArray(char character, const std::array<char, 3>& array) {
        for (char c : array) {
            if (character == c)
                return true;
        }
        return false;
    }

    bool isMatchingPair(char open, char close) {
        for (int i = 0; i < Openparentheses.size(); ++i) {
            if (open == Openparentheses[i] && close == Closeparentheses[i]) {
                return true;
            }
        }
        return false;
    }

public:
    bool isValid(std::string s) {
        std::stack<char> stack;

        for (char c : s) {
            if (isInArray(c, Openparentheses)) {
                stack.push(c);
            } else if (isInArray(c, Closeparentheses)) {
                if (stack.empty() || !isMatchingPair(stack.top(), c)) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }
};
