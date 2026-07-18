class Solution {
public:
    int getDays(vector<int>& weights, int capacity) {
        int days = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                days++;
                currentLoad = w;
            } else {
                currentLoad += w;
            }
        }
        // Return total days needed
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int minCapacity = INT_MIN;
        int maxCapacity = 0;
        for (auto i : weights) {
            maxCapacity += i;
            minCapacity = max(i, minCapacity);
        }

        int left = minCapacity;
        int right = maxCapacity;
        int res = -1;

        while (left <= right) {

            long long mid = (left + right) / 2;

            int tentativeDays = getDays(weights, mid);

            if (tentativeDays <= days) {
                res = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }

        return res;
    }
};