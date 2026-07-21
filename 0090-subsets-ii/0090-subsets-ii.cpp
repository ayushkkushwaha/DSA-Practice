class Solution {
    void helper(int idx, vector<int> temp, vector<int>& nums,
                vector<vector<int>>& res, set<vector<int>>& st);

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        helper(0, {}, nums, res, st);
        return res;
    }
};

void Solution ::helper(int idx, vector<int> temp, vector<int>& nums,
                       vector<vector<int>>& res, set<vector<int>>& st) {

    if (idx == nums.size()) {
        if (st.find(temp) == st.end()) {
            st.insert(temp);
            res.push_back(temp);
        }

        return;
    }

    temp.push_back(nums[idx]);
    helper(idx + 1, temp, nums, res, st);
    temp.pop_back();
    helper(idx + 1, temp, nums, res, st);
}
