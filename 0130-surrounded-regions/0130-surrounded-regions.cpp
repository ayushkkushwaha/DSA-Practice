class Solution {
public:
    int rowX[4] = {-1, 1, 0, 0};
    int colY[4] = {0, 0, -1, 1};
    void dfs(vector<vector<char>>& board, int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        if (board[row][col] != 'O')
            return;

        board[row][col] = '#';

        for (int i = 0; i < 4; i++) {
            dfs(board, row + rowX[i], col + colY[i], n, m);
        }
    }
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            // first and last col
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                dfs(board, i, 1, n, m);
            }

            if (board[i][m - 1] == 'O') {
                board[i][m - 1] = '#';
                dfs(board, i, m - 2, n, m);
            }
        }

        for (int i = 0; i < m; i++) {
            // first and last row
            if (board[0][i] == 'O') {
                board[0][i] = '#';
                dfs(board, 1, i, n, m);
            }
            if (board[n - 1][i] == 'O') {
                board[n - 1][i] = '#';
                dfs(board, n - 2, i, n, m);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};