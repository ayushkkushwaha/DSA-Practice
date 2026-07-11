class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mpp(n * n + 1, 0);

        int idx = 1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                mpp[grid[i][j]]++;
            }
        }

        vector<int> res(2, 0);

        for (int i = 1; i <= n * n; i++) {
            if (mpp[i] == 0)
                res[1] = i;
            else if (mpp[i] == 2)
                res[0] = i;

            cout << mpp[i] << " ";
        }

        return res;
    }
};