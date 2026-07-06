class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool isFirstRowZero = false;
        bool isFirstColZero = false;

        for (int row = 0; row < n; row++)
            if (matrix[row][0] == 0)
                isFirstRowZero = true;

        for (int col = 0; col < m; col++)
            if (matrix[0][col] == 0)
                isFirstColZero = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < n; i++)
                    matrix[i][j] = 0;
            }
        }

        if (isFirstRowZero)
            for (int row = 0; row < n; row++)
                matrix[row][0] = 0;

        if (isFirstColZero)
            for (int col = 0; col < m; col++)
                matrix[0][col] = 0;
    }
};