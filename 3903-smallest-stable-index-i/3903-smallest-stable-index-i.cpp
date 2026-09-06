class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> max_vec(n, 0);
        vector<int> min_vec(n, 0);

        int m = nums[0];

        for (int i = 0; i < n; i++) {

            m = max(m, nums[i]);
            max_vec[i] = m;
        }

        m = nums[n - 1];

        for (int i = n - 1; i >= 0; i--) {
            m = min(m, nums[i]);
            min_vec[i] = m;
        }

        for (int i = 0; i < n; i++) {
            int score = max_vec[i] - min_vec[i];
            if (score <= k)
                return i;
        }

        return -1;
    }
};