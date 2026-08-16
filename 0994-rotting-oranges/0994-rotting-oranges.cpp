class Solution {
public:
    // Check one neighbouring cell.
    // If it is a valid fresh orange, mark it as rotten and return
    // its coordinates so that it can be processed in the next BFS level.
    void helper(vector<vector<int>>& grid, int row, int col, int n, int m,
                pair<int, int>& coordinates) {

        // Ignore coordinates outside the grid.
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        // We only want to rot fresh oranges.
        // 0 = empty cell, 2 = already rotten orange.
        if (grid[row][col] != 1)
            return;

        // Mark the orange as rotten immediately.
        // This prevents the same orange from being added to the queue again.
        grid[row][col] = 2;

        // Return the newly rotten orange's position to the caller.
        coordinates = make_pair(row, col);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Number of fresh oranges still waiting to be rotten.
        int fresh = 0;

        // BFS queue containing oranges that are currently rotten
        // and can rot their neighbours.
        queue<pair<int, int>> q;

        // Four possible movement directions:
        // up, down, right, left.
        int rowX[4] = {-1, 1, 0, 0};
        int colY[4] = {0, 0, 1, -1};

        // Put all initially rotten oranges into the queue.
        // This is important because all of them start spreading
        // the rot at the same time.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                // Count how many fresh oranges need to be rotten.
                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int time = 0;

        // Each BFS level represents one minute.
        // We continue while there are rotten oranges that can spread
        // the rot and there are still fresh oranges remaining.
        while (!q.empty() && fresh > 0) {

            // Process only the oranges that were already rotten
            // at the beginning of this minute.
            int size = q.size();

            // Moving from one BFS level to the next means one minute passed.
            time++;

            while (size--) {
                pair<int, int> front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;

                // Try all four neighbouring cells.
                for (int i = 0; i < 4; i++) {

                    // (-1, -1) means no fresh orange was found
                    // at this neighbouring position.
                    pair<int, int> coord = make_pair(-1, -1);

                    helper(
                        grid,
                        row + rowX[i],
                        col + colY[i],
                        n,
                        m,
                        coord
                    );

                    // A valid fresh orange was found and made rotten.
                    if (coord.first != -1) {

                        // Add it to the queue so it can spread the rot
                        // during the next minute.
                        q.push(coord);

                        // One less fresh orange remains.
                        fresh--;
                    }
                }
            }
        }

        // If fresh oranges are still left, they could not be reached
        // by any rotten orange, so it is impossible to rot all of them.
        if (fresh > 0)
            return -1;

        return time;
    }
};