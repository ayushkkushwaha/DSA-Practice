class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row,
             int col, int n, int m) {

        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        if(visited[row][col] == true || grid[row][col] == '0')
            return;

        visited[row][col] = true;

        dfs(grid, visited, row + 1, col, n, m);
        dfs(grid, visited, row - 1, col, n, m);
        dfs(grid, visited, row, col + 1, n, m);
        dfs(grid, visited, row, col - 1, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j, n, m);
                    res++;
                }
            }
        }

        return res;
    }
};