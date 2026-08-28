class Solution {
public:

    // Check whether the given cell is inside the grid.
    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || col < 0 || row >= n || col >= m)
            return false;

        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        // res[row][col] stores the minimum effort required
        // to reach cell (row, col) from (0, 0).
        //
        // Initially, every cell is unreachable, so set it to INT_MAX.
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));

        // Min-heap storing:
        // {current minimum effort, {row, col}}
        //
        // The cell with the smallest effort is processed first.
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        // Starting cell has effort 0 because no edge has been traversed.
        pq.push({0, {0, 0}});
        res[0][0] = 0;

        // Four possible movement directions:
        // up, down, left, right.
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        // Dijkstra's algorithm.
        while (!pq.empty()) {

            // Get the cell with the smallest known effort.
            pair<int, pair<int, int>> curr = pq.top();
            pq.pop();

            int dist = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            // If this is an outdated entry, skip it.
            // A better effort for this cell has already been found.
            if (dist > res[row][col])
                continue;

            // Explore all four neighbouring cells.
            for (int i = 0; i < 4; i++) {

                int r = row + x[i];
                int c = col + y[i];

                // Ignore cells outside the grid.
                if (!isValid(r, c, n, m))
                    continue;

                // Effort required to move from current cell
                // to the neighbouring cell.
                int absDiff = abs(heights[row][col] - heights[r][c]);

                // Path effort is NOT the sum of edge differences.
                // It is the maximum edge difference encountered
                // along the path.
                //
                // Therefore:
                // newWeight = max(previous path effort, current edge effort)
                int newWeight = max(absDiff, dist);

                // If this path reaches the neighbour with less effort,
                // update its minimum effort.
                if (newWeight < res[r][c]) {

                    res[r][c] = newWeight;

                    // Push the improved state into the min-heap.
                    pq.push({newWeight, {r, c}});
                }
            }
        }

        // Minimum effort required to reach the bottom-right cell.
        return res[n - 1][m - 1];
    }
};