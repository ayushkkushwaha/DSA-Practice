class Solution {
    vector<string> res;

public:
    vector<string> merge(vector<int>& nums, vector<string>& names, int left,
                         long long mid, int right) {

        int leftSize = mid - left + 1;
        int rightSize = right - mid;

        // copy data to vector
        vector<int> temp1(leftSize), temp2(rightSize);
        vector<string> temp3(leftSize), temp4(rightSize);
        // leftside copy
        for (int i = 0; i < leftSize; i++) {
            temp1[i] = nums[left + i];
            temp3[i] = names[left + i];
        }
        // right side
        for (int i = 0; i < rightSize; i++) {
            temp2[i] = nums[mid + i + 1];
            temp4[i] = names[mid + i + 1];
        }

        int i = 0, j = 0;
        int k = left;

        while (i < leftSize && j < rightSize) {
            if (temp1[i] >= temp2[j]) {
                nums[k] = temp1[i];
                names[k] = temp3[i++];
            } else {
                nums[k] = temp2[j];
                names[k] = temp4[j++];
            }

            k++;
        }

        while (i < leftSize) {
            names[k] = temp3[i];
            nums[k++] = temp1[i++];
        }

        while (j < rightSize) {
            names[k] = temp4[j];
            nums[k++] = temp2[j++];
        }

        return names;
    }

    vector<string> mergeSort(vector<int>& nums, vector<string>& names, int left,
                             int right) {

        if (right <= left)
            return names;

        long long mid = (left + right) / 2;

        mergeSort(nums, names, left, mid);
        mergeSort(nums, names, mid + 1, right);
        return merge(nums, names, left, mid, right);
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        return mergeSort(heights, names, 0, n - 1);
    }
};