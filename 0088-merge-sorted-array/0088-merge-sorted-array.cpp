class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if (m == 0) {
            nums1 = nums2;
            return;
        }
        if (n == 0)
            return;

        int right = n - 1;
        int left = m - 1;
        int mid = nums1.size() - 1;

        while (right >= 0 && left >= 0) {

            if (nums1[left] >= nums2[right]) {
                swap(nums1[mid], nums1[left]);
                mid--;
                left--;
            }

            else if (nums1[left] <= nums2[right]) {
                nums1[mid] = nums2[right];
                mid--;
                right--;
            }
        }

        while (mid >= 0) {
            if (left >= 0) {
                nums1[mid--] = nums1[left--];
            }

            if (right >= 0) {
                nums1[mid--] = nums2[right--];
            }
        }
    }
};