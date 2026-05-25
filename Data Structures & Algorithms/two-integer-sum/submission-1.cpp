class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int remaining=-1;
        vector<int> ans;

        for( int i=0;i<nums.size();i++){
            remaining = target-nums[i];
            int j=i+1;

            while(j<nums.size()){
                if(remaining == nums[j]){
                    ans.push_back(i);
                    ans.push_back(j);
                return ans;
                }
                j++;
            }
        }

        return ans;
    }
};
