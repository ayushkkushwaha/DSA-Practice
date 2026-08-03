class Solution {
public:
    string removeStars(string s) {
        int j = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                j--;
                s.erase(s.begin() + i);
                continue;
            } else if (s[i] != '*' && j < 0) {
                j++;
                s.erase(s.begin() + i);
                continue;
            }
        }

        return s;
    }
};