/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // DFS checks whether there exists a root-to-leaf path
    // whose node values add up to targetSum.
    bool dfs(TreeNode* root, int sum, int targetSum) {

        // Base case:
        // If the current node doesn't exist, this path is invalid.
        if (!root)
            return false;

        // Include the current node's value in the running path sum.
        sum += root->val;

        // If we've reached a leaf node,
        // verify whether the accumulated sum matches the target.
        if (!root->left && !root->right && sum == targetSum)
            return true;

        // Explore both subtrees.
        // If either subtree contains a valid path, return true.
        // Short-circuit evaluation stops searching once a valid path is found.
        return dfs(root->left, sum, targetSum) ||
               dfs(root->right, sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        // Start DFS from the root with an initial path sum of 0.
        return dfs(root, 0, targetSum);
    }
};