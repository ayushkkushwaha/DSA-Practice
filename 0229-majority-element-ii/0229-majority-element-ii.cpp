class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (res.size() == 0 || nums[i] != res[0]) {
                int cnt = 0;
                for (int j = 0; j < nums.size(); j++)
                    if (nums[i] == nums[j])
                        cnt++;

                if (cnt > (nums.size() / 3))
                    res.push_back(nums[i]);
            }

            if (res.size() == 2)
                break;
        }

        return res;
    }
};