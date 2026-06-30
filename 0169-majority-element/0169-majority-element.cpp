class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(auto ele : nums)
            mpp[ele]++;
        
        int majority = 0;

        for(auto ele : mpp){
            if(n/2 < ele.second)
                majority = ele.first;
        }
        return majority;
    }
};