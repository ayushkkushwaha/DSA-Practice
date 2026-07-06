class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col <= row; col++) {

                if (col == 0 || col == row)
                    ans[row].push_back(1);

                else if (row > 0 && col > 0 && col < numRows) {
                    ans[row].push_back(ans[row - 1][col - 1] +
                                       ans[row - 1][col]);
                }

                cout << ans[row][col];
            }
            cout << endl;
        }

        return ans;
    }
};