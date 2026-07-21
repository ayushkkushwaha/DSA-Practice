class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        rec(1, {}, res, k, n);
        return res;
    }

    set<vector<int>> st;

    void rec(int idx, vector<int> temp, vector<vector<int>>& res, int k,
             int target) {
        for (auto i : temp)
            cout << i << " ";
        cout << endl;

        if (target == 0 && temp.size() == k) {
            res.push_back(temp);
            return;
        }
        if (target < 0 || idx > 9)
            return;
        temp.push_back(idx);
        rec(idx + 1, temp, res, k, target - idx);
        temp.pop_back();
        rec(idx + 1, temp, res, k, target);
    }
};