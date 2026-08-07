/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int sum, int targetSum, vector<int> temp,
             vector<vector<int>>& res) {
        if (!root)
            return;

        sum += root->val;
        temp.push_back(root->val);
        if (!root->right && !root->left) {
            if (sum == targetSum)
                res.push_back(temp);
            return;
        }

        dfs(root->left, sum, targetSum, temp, res);
        dfs(root->right, sum, targetSum, temp, res);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        dfs(root, 0, targetSum, {}, res);
        return res;
    }
};