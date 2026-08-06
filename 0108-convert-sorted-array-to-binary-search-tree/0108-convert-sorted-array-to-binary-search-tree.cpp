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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // helper function
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {

        // if left crossed right then return
        if (right < left)
            return NULL;

        // find mid
        int mid = left + (right - left) / 2;
        // create a node
        TreeNode* root = new TreeNode(nums[mid]);

        // check in left half
        root->left = helper(nums, left, mid - 1);
        // check in right half
        root->right = helper(nums, mid + 1, right);

        return root;
    }
};