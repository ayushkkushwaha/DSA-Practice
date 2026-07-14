class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            long long mid = (left + right) / 2;

            int prv = (mid - 1 + n) % n;
            int nxt = (mid + 1) % n;

            if (nums[mid] != nums[prv] && nums[mid] != nums[nxt])
                return nums[mid];

            if (mid % 2 == 0) {

                if (mid + 1 < n && nums[mid] != nums[nxt])
                    right = mid - 1;
                else if (mid - 1 >= 0 && nums[mid] != nums[prv])
                    left = mid + 1;
                else
                    return nums[mid];

            } else {

                if (mid + 1 < n && nums[mid] != nums[nxt])
                    left = mid + 1;
                else if (mid - 1 >= 0 && nums[mid] != nums[prv])
                    right = mid - 1;
                else
                    return nums[mid];
            }
        }

        return -1;
    }
};