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
    void helper(TreeNode* root, string temp, int& total) {
        // If the current node is NULL, stop the recursion
        if (!root)
            return;

        // Add the current node's value to the path string
        temp += to_string(root->val);

        // If the current node is a leaf node
        if (!root->right && !root->left) {
            // Convert the complete root-to-leaf path into an integer
            // and add it to the total sum
            total += stoi(temp);

            // No children to process, so return
            return;
        }

        // Recursively process the left subtree
        helper(root->left, temp, total);

        // Recursively process the right subtree
        helper(root->right, temp, total);

        // No explicit backtracking is required because
        // temp is passed by value, so each recursive call
        // works with its own copy of the string
    }

    int sumNumbers(TreeNode* root) {
        int total = 0;
        helper(root, "", total);
        return total;
    }
};