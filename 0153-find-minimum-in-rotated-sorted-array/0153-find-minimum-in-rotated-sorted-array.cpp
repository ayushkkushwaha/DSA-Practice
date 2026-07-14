class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right) {

            if (nums[left] <= nums[right])
                return nums[left];
            
            long long mid = (left + right) / 2;

            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;

            if (nums[mid] < nums[prev] && nums[mid] < nums[next])
                return nums[mid];

            else if (nums[mid] < nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }
};