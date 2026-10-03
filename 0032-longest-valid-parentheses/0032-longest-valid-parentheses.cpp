class Solution {
public:
    int longestValidParentheses(string s) {

        int longest = 0;
        int open = 0, close = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close) {
                longest = max(longest, 2 * close);
            } else if (close > open)
                open = close = 0;
        }

        open = close = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(')
                open++;
            else
                close++;

             if (open == close) {
                longest = max(longest, 2 * open);
            } else if (close < open)
                open = close = 0;
        }

        return longest;
    }
};