class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        pair<int, int> min_ele = {-1, INT_MAX};
        pair<int, int> max_ele = {-1, INT_MIN};

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min_ele.second) {
                min_ele.second = nums[i];
                min_ele.first = i;
            }

            if (nums[i] > max_ele.second) {
                max_ele.second = nums[i];
                max_ele.first = i;
            }
        }

        int n = nums.size();

        int minIdx = min_ele.first;
        int maxIdx = max_ele.first;

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        int delFront = right + 1;
        int delBack = n - left;

        int delBoth = (left + 1) + (n - right);

        return min({delFront, delBack, delBoth});
    }
};