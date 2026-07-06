class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        while (top <= bottom && left <= right) {

            // row=0 ,col=0->n;
            for (int col = left; col <= right; col++) {
                ans.push_back(matrix[top][col]);
            }
            top++;

            // col = m-1 , row=0->m;
            for (int row = top; row <= bottom; row++) {
                ans.push_back(matrix[row][right]);
            }
            right--;

            // row = m-1, col = n->0
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    ans.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            // col = 0, row = m->0
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    ans.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return ans;
    }
};