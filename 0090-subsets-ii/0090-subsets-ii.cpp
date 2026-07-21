class Solution {
    void helper(int idx, vector<int> temp, vector<int>& nums,
                vector<vector<int>>& res);

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(0, {}, nums, res);
        return res;
    }
};

void Solution::helper(int idx, vector<int> temp, vector<int>& nums,
                      vector<vector<int>>& res) {

    if (idx == nums.size()) {

        res.push_back(temp);

        return;
    }

    temp.push_back(nums[idx]);
    helper(idx + 1, temp, nums, res);
    temp.pop_back();

    while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
        idx++;
    }
    helper(idx + 1, temp, nums, res);
}
