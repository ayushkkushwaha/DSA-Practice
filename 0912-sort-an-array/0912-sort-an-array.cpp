class Solution {
public:
    void merge(vector<int>& nums, int left, long long mid, int right) {

        int leftSize = mid - left + 1;
        int rightSize = right - mid;

        // copy data to vector
        vector<int> temp1(leftSize), temp2(rightSize);
        // leftside copy
        for (int i = 0; i < leftSize; i++) {
            temp1[i] = nums[left + i];
        }
        // right side
        for (int i = 0; i < rightSize; i++) {
            temp2[i] = nums[mid + i + 1];
        }

        int i = 0, j = 0;
        int k = left;

        while (i < leftSize && j < rightSize) {
            if (temp1[i] <= temp2[j]) {
                nums[k] = temp1[i++];
            } else {
                nums[k] = temp2[j++];
            }

            k++;
        }

        while (i < leftSize) {
            nums[k++] = temp1[i++];
        }

        while (j < rightSize) {
            nums[k++] = temp2[j++];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {

        if (right <= left)
            return;

        long long mid = (left + right) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};