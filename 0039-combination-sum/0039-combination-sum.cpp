class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        rec(0, {}, candidates, res, target);
        return res;
    }

    set<vector<int>> st;

    void rec(int idx, vector<int> temp, vector<int>& cand,
             vector<vector<int>>& res, int target) {

        if (target < 0 || idx == cand.size())
            return;

        if (target == 0) {
            if (st.find(temp) == st.end()) {
                res.push_back(temp);
                st.insert(temp);
            }

            return;
        }

        temp.push_back(cand[idx]);
        // single inc.
        rec(idx + 1, temp, cand, res, target - cand[idx]);
        // multi inc.
        rec(idx, temp, cand, res, target - cand[idx]);
        // exc.
        temp.pop_back();

        rec(idx + 1, temp, cand, res, target);
    }
};