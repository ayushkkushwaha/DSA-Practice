class Solution {
public:
    void traverse(vector<vector<int>>& grid, int m, int n, int& cnt,
                  int row, int col, int dr, int dc) {

        row += dr;
        col += dc;

        if (row < 0 || row >= m || col < 0 || col >= n)
            return;

        // stop at wall or another guard
        if (grid[row][col] == 2 || grid[row][col] == 3)
            return;

        if (grid[row][col] == 0) {
            grid[row][col] = 1;
            cnt--;
        }

        traverse(grid, m, n, cnt, row, col, dr, dc);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        vector<vector<int>> grid(m, vector<int>(n, 0));

        int cnt = m * n;

        // walls
        for (auto &w : walls) {
            grid[w[0]][w[1]] = 2;
            cnt--;
        }

        // guards
        for (auto &g : guards) {
            grid[g[0]][g[1]] = 3;
            cnt--;
        }

        // four directions for every guard
        for (auto &g : guards) {
            int r = g[0];
            int c = g[1];

            traverse(grid, m, n, cnt, r, c, 0, 1);   // right
            traverse(grid, m, n, cnt, r, c, 0, -1);  // left
            traverse(grid, m, n, cnt, r, c, 1, 0);   // down
            traverse(grid, m, n, cnt, r, c, -1, 0);  // up
        }

        return cnt;
    }
};