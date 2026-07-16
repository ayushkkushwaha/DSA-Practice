class Solution {
public:
    long long getTime(vector<int>& piles, int speed) {

        long long totalHrs = 0;
        for (auto i : piles)
            totalHrs += ((long long)i + speed - 1) / speed;
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxPiles = INT_MIN;
        int res = 0;

        for (auto i : piles)
            maxPiles = max(maxPiles, i);

        int left = 1;
        int right = maxPiles;

        while (left <= right) {

            int mid = (left + right) / 2;

            long long reqTime = getTime(piles, mid);


                if (reqTime <= h) {
                    res = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
        }

        return res;
    }
};