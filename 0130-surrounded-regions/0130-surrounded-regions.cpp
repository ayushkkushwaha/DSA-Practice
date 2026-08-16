class Solution {
public:
    // Four possible directions:
    // up, down, left, right.
    int rowX[4] = {-1, 1, 0, 0};
    int colY[4] = {0, 0, -1, 1};

    // DFS is used to find every 'O' connected to a boundary 'O'.
    // Any 'O' connected to the boundary can NOT be surrounded,
    // so we temporarily mark it as '#' to remember that it is safe.
    void dfs(vector<vector<char>>& board, int row, int col, int n, int m) {

        // Stop if the current position is outside the board.
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        // We only care about unvisited 'O's.
        // 'X' and '#' should not be processed.
        if (board[row][col] != 'O')
            return;

        // Mark this 'O' as '#'.
        // '#' means: this O is connected to the boundary,
        // therefore it must NOT be captured.
        board[row][col] = '#';

        // Visit all four neighbouring cells to find
        // other 'O's connected to this boundary region.
        for (int i = 0; i < 4; i++) {
            dfs(board, row + rowX[i], col + colY[i], n, m);
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        /*
            Main idea of the problem:

            Instead of finding which O's are surrounded,
            find which O's are NOT surrounded.

            Any O connected to the boundary has an escape route
            to the outside of the board, so it cannot be captured.

            Therefore:
            1. Find all boundary O's.
            2. DFS from them and mark connected O's as '#'.
            3. Remaining O's are completely surrounded -> change to X.
            4. Change '#' back to O.
        */

        // Check the first and last column.
        // These cells are on the left/right boundary.
        for (int i = 0; i < n; i++) {

            // If an O is on the left boundary, it is safe.
            if (board[i][0] == 'O') {
                board[i][0] = '#';

                // Start DFS from its neighbour.
                // The boundary O itself is already marked '#'.
                dfs(board, i, 1, n, m);
            }

            // If an O is on the right boundary, it is also safe.
            if (board[i][m - 1] == 'O') {
                board[i][m - 1] = '#';

                // The boundary O itself is already marked '#',
                // so start DFS from the cell next to it.
                dfs(board, i, m - 2, n, m);
            }
        }

        // Check the first and last row.
        // These cells are on the top/bottom boundary.
        for (int i = 0; i < m; i++) {

            // If an O is on the top boundary, it cannot be surrounded.
            if (board[0][i] == 'O') {
                board[0][i] = '#';

                // Start DFS from the cell below it.
                dfs(board, 1, i, n, m);
            }

            // If an O is on the bottom boundary, it cannot be surrounded.
            if (board[n - 1][i] == 'O') {
                board[n - 1][i] = '#';

                // Start DFS from the cell above it.
                dfs(board, n - 2, i, n, m);
            }
        }

        /*
            Now every boundary-connected O has been marked '#'.

            Therefore:
                'O' -> surrounded -> change to 'X'
                '#' -> safe -> change back to 'O'
        */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // This O was never connected to the boundary,
                // so it is completely surrounded by X.
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                // This O was connected to the boundary,
                // so restore it back to O.
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};