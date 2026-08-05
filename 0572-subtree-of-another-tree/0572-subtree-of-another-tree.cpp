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
    bool helper(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        if (!p || !q)
            return false;

        if (p->val != q->val)
            return false;

        return helper(p->left, q->left) && helper(p->right, q->right);
    }

    bool inOrder(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;

        if (root->val == subRoot->val)
            if (helper(root, subRoot))
                return true;

        return inOrder(root->left, subRoot) || inOrder(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return inOrder(root, subRoot);
    }
};