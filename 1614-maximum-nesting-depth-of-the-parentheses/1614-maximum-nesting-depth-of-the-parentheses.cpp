class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int open = 0;

        for (auto i : s) {

            if (i == '(') {
                open++;
            } else if (i == ')') {
                open--;
            }

            res = max(open, res);
        }

        return res;
    }
};