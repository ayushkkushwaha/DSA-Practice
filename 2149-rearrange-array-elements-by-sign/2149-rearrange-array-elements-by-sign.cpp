class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> ans(nums.size(), 0);

        int posIdx = 0;
        int negIdx = 1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] >= 0) {
                ans[posIdx] = nums[i];
                posIdx += 2;
            } else {
                ans[negIdx] = nums[i];
                negIdx += 2; 
            }
        }

        return ans;
    }
};