// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        long long right = n;

        while (left <= right) {
            long long mid = (left + right) / 2;

            if (!isBadVersion(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};