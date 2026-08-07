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
    void bfs(TreeNode* root, vector<vector<int>>& res, int lvl) {
        if (!root)
            return;

        if (res.size() <= lvl)
            res.push_back({});

        res[lvl].push_back(root->val);

        bfs(root->left, res, lvl + 1);
        bfs(root->right, res, lvl + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<vector<int>> data;
        bfs(root,data,0);

        for (auto& it : data)
            res.push_back(accumulate(it.begin(), it.end(),0.0) / it.size());

        return res;
    }
};