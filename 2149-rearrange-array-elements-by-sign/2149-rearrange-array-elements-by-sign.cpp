class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> posInt;
        vector<int> negInt;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                posInt.push_back(nums[i]);
            else
                negInt.push_back(nums[i]);
        }

        int posIdx = 0;
        int negIdx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                nums[i] = posInt[posIdx++];
            else
                nums[i] = negInt[negIdx++];
        }
        return nums;
    }
};