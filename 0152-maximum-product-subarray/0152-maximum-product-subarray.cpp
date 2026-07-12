class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int leftToRight = 1;
        int maxPrd = INT_MIN;
        int n = nums.size();
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (leftToRight == 0)
                leftToRight = 1;

            leftToRight *= nums[i];

            maxPrd = max(leftToRight, maxPrd);
        }

        int rightToLeft = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (rightToLeft == 0)
                rightToLeft = 1;

            rightToLeft *= nums[i];

            maxPrd = max(rightToLeft, maxPrd);
        }

        return maxPrd;
    }
};