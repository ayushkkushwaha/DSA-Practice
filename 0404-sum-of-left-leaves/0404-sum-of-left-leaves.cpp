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
    int sumOfLeftLeaves(TreeNode* root) {
        // Base case: empty subtree contributes 0
        if (!root)
            return 0;

        int sum = 0;

        // Check if the left child exists and is a leaf
        // (i.e., it has no left or right child)
        if (root->left &&
            !root->left->left &&
            !root->left->right)
            sum += root->left->val;

        // Recursively calculate the sum from the left and right subtrees
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        // Return the total sum of left leaves in this subtree
        return sum;
    }
};