class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        helper(1, res, {}, n, k);
        return res;
    }

    void helper(int idx, vector<vector<int>>& res, vector<int> temp, int n,
                int k) {

        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }

        for (int i = idx; i <= n; i++) {
            temp.push_back(i);
            helper(i + 1, res, temp, n, k);
            temp.pop_back();
        }
    }
};