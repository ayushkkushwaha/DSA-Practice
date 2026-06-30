class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0;
        int candidate = 0;

        for (auto ele : nums) {
            if (vote == 0)
                candidate = ele;

            if (candidate == ele)
                vote++;
            else
                vote--;
        }

        return candidate;
    }
};