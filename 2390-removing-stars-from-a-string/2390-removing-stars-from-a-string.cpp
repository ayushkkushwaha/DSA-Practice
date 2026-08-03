class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        string ans = "";

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                j--;
                continue;
            } else if (s[i] != '*' && j < 0) {
                j++;
                continue;
            }

            if (j == 0)
                ans.push_back(s[i]);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};