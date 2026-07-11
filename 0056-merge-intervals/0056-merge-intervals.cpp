class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            int left = intervals[i][0];
            int right = intervals[i][1];

            if (!res.empty() && res.back()[1] >= right){
                continue;
            }

            for (int j = i + 1; j < intervals.size(); j++) {
                if (right >= intervals[j][0])
                    right = max(intervals[j][1], right);
                else
                    break;
            }

            res.push_back({left,right});
        }

        return res;
    }
};