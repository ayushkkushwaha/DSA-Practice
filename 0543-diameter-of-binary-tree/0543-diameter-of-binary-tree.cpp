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
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int left = 1 + height(root->left);
        int right = 1 + height(root->right);

        return max(left, right);
    }

    void fetchDiameter(TreeNode* root, int temp, int& ans) {
        if (!root)
            return;

        int left = height(root->left);
        int right = height(root->right);

        temp = left + right;
        ans = max(temp, ans);

        fetchDiameter(root->left, temp, ans);
        fetchDiameter(root->right, temp, ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        fetchDiameter(root, 0, ans);
        return ans;
    }
};