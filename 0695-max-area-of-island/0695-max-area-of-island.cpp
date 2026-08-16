class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int n, int m, int x[],
             int y[], int& temp) {
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        if (grid[row][col] != 1)
            return;

        grid[row][col] = -1;
        temp++;

        for (int i = 0; i <= 3; i++)
            dfs(grid, row + x[i], col + y[i], n, m, x, y, temp);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int res = 0;
        int n = grid.size();
        int m = grid[0].size();

        int xCord[4] = {-1, 1, 0, 0};
        int yCord[4] = {0, 0, 1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int temp = 0;
                    dfs(grid, i, j, n, m, xCord, yCord, temp);
                    res = max(temp, res);
                }
            }
        }

        return res;
    }
};