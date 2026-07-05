class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int len = 0;
        int subLen = 0;
        set<int> st(nums.begin(), nums.end());

        while (!st.empty()) {

            int curr = *st.rbegin();
            st.erase(--st.end());

            subLen++;

            if (st.empty()) {
                len = max(len, subLen);
                break;
            }

            if (curr - 1 != *st.rbegin()) {
                len = max(len, subLen);
                subLen = 0;
            }
        }

        return len;
    }
};