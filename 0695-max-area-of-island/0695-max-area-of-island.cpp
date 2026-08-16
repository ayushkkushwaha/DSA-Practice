class Solution {
public:
    // DFS visits every 1 connected to the current cell.
    // temp keeps track of the number of cells in the current island.
    void dfs(vector<vector<int>>& grid, int row, int col, int n, int m,
             int x[], int y[], int& temp) {

        // Stop if we move outside the grid.
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        // We only want to visit land cells.
        // 0 = water
        // -1 = already visited land
        if (grid[row][col] != 1)
            return;

        // Mark the current land cell as visited.
        // This prevents visiting the same cell again.
        grid[row][col] = -1;

        // One more cell belongs to the current island.
        temp++;

        // Explore all 4 possible directions:
        // up, down, right, left.
        for (int i = 0; i <= 3; i++)
            dfs(grid, row + x[i], col + y[i], n, m, x, y, temp);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        // Stores the maximum island area found so far.
        int res = 0;

        int n = grid.size();
        int m = grid[0].size();

        // Directions for moving to neighbouring cells.
        // (-1, 0) -> up
        // (1, 0)  -> down
        // (0, 1)  -> right
        // (0, -1) -> left
        int xCord[4] = {-1, 1, 0, 0};
        int yCord[4] = {0, 0, 1, -1};

        // Visit every cell in the grid.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Finding a 1 means we found a new unvisited island.
                if (grid[i][j] == 1) {

                    // Count the area of this island.
                    int temp = 0;

                    // DFS will visit every connected 1 and
                    // increase temp for each cell.
                    dfs(grid, i, j, n, m, xCord, yCord, temp);

                    // Compare this island's area with the
                    // maximum area found so far.
                    res = max(temp, res);
                }
            }
        }

        return res;
    }
};