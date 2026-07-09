class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum =
                        1LL * nums[left] + nums[right] + nums[i] + nums[j];

                    if (sum == target) {
                        res.push_back(
                            {nums[left], nums[right], nums[i], nums[j]});
                        ++left;
                        --right;

                        while (left < right && nums[left] == nums[left - 1])
                            ++left;

                        while (right > left && nums[right] == nums[right + 1])
                            --right;
                    }

                    else if (sum < target)
                        ++left;
                    else
                        --right;
                }
            }
        }

        return res;
    }
};