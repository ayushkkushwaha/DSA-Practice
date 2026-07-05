class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find next greater the pivot
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // for next permutation after pivot we return the small no as possible
        reverse(nums.begin() + pivot + 1, nums.end());
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        bool doNext = true;

        while (doNext) {
            ans.push_back(nums);
            nextPermutation(nums);
            if (find(ans.begin(), ans.end(), nums) != ans.end())
                break;
        }

        return ans;
    }
};