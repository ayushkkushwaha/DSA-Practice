class Solution {
public:
    vector<int> generateRow(int row) {
        vector<int> ans;
        int ele = 1;
        ans.push_back(1);

        for (int col = 1; col < row; col++) {
            ele = ele * (row - col);
            ele /= col;
            ans.push_back(ele);
        }

        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
            ans.push_back(generateRow(i));

        return ans;
    }
};