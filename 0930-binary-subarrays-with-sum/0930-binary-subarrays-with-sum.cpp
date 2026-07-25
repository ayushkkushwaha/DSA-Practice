class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int count = 0;

        int n = nums.size();
        int prefSum = 0;
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            prefSum += nums[i];

            if (prefSum == k)
                count++;

            if (mpp.find(prefSum - k) != mpp.end()) {
                count += mpp[prefSum - k];
            }

            mpp[prefSum]++;
        }

        return count;
    }
};