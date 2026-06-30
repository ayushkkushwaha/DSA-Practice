class Solution {
public:
    int majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        int res = -1;

        int mid = left + (right - left) / 2;

        return nums[mid];
    }
};