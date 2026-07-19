class Solution {
public:
    int getDays(vector<int>& weights, int cap) {
        int load = 0;
        int days = 1;

        for (auto i : weights) {
            if (load + i > cap) {
                days++;
                load = i;
            } else
                load += i;
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int minC = 0;
        int maxC = 0;

        for (auto i : weights) {
            minC = max(i, minC);
            maxC += i;
        }

        int left = minC;
        int right = maxC;
        int ans = -1;

        while (left <= right) {

            long long mid = (left + right) / 2;

            if (getDays(weights, mid) <= days) {
                ans = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }

        return ans;
    }
};