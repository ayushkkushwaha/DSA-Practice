class Solution {
public:
    // this function rottens neighbour oranges and mark as visited(0)
    void helper(vector<vector<int>>& grid, int row, int col, int n, int m,
                pair<int, int>& coordinates) {
        // check for out of bounds
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        // no sense to see this
        if (grid[row][col] == 0)
            return;

        // mark visited and save coordinates in vector to process further
        grid[row][col] = 0;
        coordinates = make_pair(row, col);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        queue<pair<int, int>> q;

        int rowX[4] = {-1, 1, 0, 0};
        int colY[4] = {0, 0, 1, -1};

        // store no. of fresh oranges count and push rottens in queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int time = 0;
        while (!q.empty() && fresh > 0) {

            int size = q.size();
            time++;
            while (size--) {
                pair<int, int> front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;

                // from q.front check its neighbour can be rottern or not
                for (int i = 0; i < 4; i++) {
                    pair<int, int> coord = make_pair(-1, -1);
                    //check in all dxn
                    helper(grid, row + rowX[i], col + colY[i], n, m, coord);

                    if (coord.first != -1) {
                        // save it in queue
                        q.push(coord);
                        // reduce the no. of rottern
                        fresh--;
                    }
                }
            }
        }

        if (fresh > 0)
            return -1;

        return time;
    }
};