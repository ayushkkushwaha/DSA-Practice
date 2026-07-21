class Solution {
public:
    set<vector<int>> st;
    void getPer(int idx, vector<vector<int>>& res, vector<int>& nums) {

        if (idx == nums.size() - 1) {
            if (st.find(nums) == st.end()) {
                st.insert(nums);
                res.push_back(nums);
            }

            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            getPer(idx + 1, res, nums);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        getPer(0, res, nums);
        return res;
    }
};