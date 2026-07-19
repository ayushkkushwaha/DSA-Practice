class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int count = 0;
        int n = arr.size();

        vector<int> ele;

        for (int i = 1;; i++) {

            bool isFound = false;
            for (auto j : arr) {
                if (i == j)
                    isFound = true;
            }
            if (!isFound)
                ele.push_back(i);
            
            if(ele.size() > k)
                break;
        }

        return ele[k - 1];
    }
};