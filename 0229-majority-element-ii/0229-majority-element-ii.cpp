class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        int refCount = nums.size() / 3;

        for (int i = 0; i < nums.size(); i++) {

            mp[nums[i]]++;

            if (mp[nums[i]] == refCount + 1) {
                res.push_back(nums[i]);
            }

        }

        return res;
    }
};