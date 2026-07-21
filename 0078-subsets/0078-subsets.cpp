class Solution {
public:
    void helper(int idx, vector<int> temp, vector<int>& nums,
                vector<vector<int>>& res) {

        if (idx == nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        helper(idx + 1, temp, nums, res);
        temp.pop_back();
        helper(idx + 1, temp, nums, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, {}, nums, res);
        return res;
    }
};