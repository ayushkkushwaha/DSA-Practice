class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;
        helper(1, k, n, {}, res);
        return res;
    }

    void helper(int itr, int k, int n, vector<int> temp,
                vector<vector<int>>& res) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for (int i = itr; i <= n; i++) {
            temp.push_back(i);
            helper(i + 1, k, n, temp, res);
            temp.pop_back();
        }
    }
};