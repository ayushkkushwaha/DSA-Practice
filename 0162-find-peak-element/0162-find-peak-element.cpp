class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 1;
        int n = nums.size();
        int right = n - 2;

        if (n <= 1)
            return 0;

        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        while (left <= right) {
            long long mid = (left + right) / 2;

            int prv = (mid - 1 + n) % n;
            int nxt = (mid + 1) % n;

            if (nums[mid] > nums[prv] && nums[mid] > nums[nxt])
                return mid;
            else if (nums[mid] < nums[prv])
                right = mid - 1;
            else if (nums[mid] < nums[nxt])
                left = mid + 1;
        }

        return -1;
    }
};