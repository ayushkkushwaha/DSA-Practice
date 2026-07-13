class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suf = 1;
        int res = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (pre == 0)
                pre = 1;
            if (suf == 0)
                suf = 1;

            pre *= nums[i];
            suf *= nums[n - i - 1];

            res = max(res, max(pre, suf));
        }

        return res;
    }
};