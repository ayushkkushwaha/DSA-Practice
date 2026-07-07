class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int vote1 = 0, vote2 = 0, cand1 = INT_MIN, cand2 = INT_MIN;
        int n = nums.size();

        for (auto i : nums) {
            if (vote1 == 0 && cand2 != i) {
                vote1 = 1;
                cand1 = i;
            } else if (vote2 == 0 && cand1 != i) {
                vote2 = 1;
                cand2 = i;
            } else if (cand1 == i)
                vote1++;
            else if (cand2 == i)
                vote2++;
            else {
                vote1--, vote2--;
            }
        }

        vector<int> res;
        vote1 = 0, vote2 = 0;

        for (auto i : nums) {
            if (cand1 == i)
                vote1++;
            else if (cand2 == i)
                vote2++;
        }

        if (vote1 > n / 3)
            res.push_back(cand1);
        if (vote2 > n / 3)
            res.push_back(cand2);

        return res;
    }
};