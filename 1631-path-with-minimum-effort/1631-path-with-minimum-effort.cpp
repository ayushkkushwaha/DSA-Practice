class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        if (row < 0 || col < 0 || row >= n || col >= m)
            return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});
        res[0][0] = 0;

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        while (!pq.empty()) {

            pair<int, pair<int, int>> curr = pq.top();
            pq.pop();

            int dist = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if (dist > res[row][col])
                continue;

            for (int i = 0; i < 4; i++) {
                int r = row + x[i];
                int c = col + y[i];

                if (!isValid(r, c, n, m))
                    continue;

                int absDiff = abs(heights[row][col] - heights[r][c]);
                int newWeight = max(absDiff, dist);

                if (newWeight < res[r][c]) {
                    res[r][c] = newWeight;
                    pq.push({newWeight, {r, c}});
                }
            }
        }

        return res[n - 1][m - 1];
    }
};