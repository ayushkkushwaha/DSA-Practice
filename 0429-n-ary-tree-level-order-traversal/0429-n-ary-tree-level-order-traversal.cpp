/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node* root, int lvl, vector<vector<int>>& res) {
        if (!root)
            return;

        if (lvl >= res.size())
            res.push_back({});

        res[lvl].push_back(root->val);

        for (auto curr : root->children)
            dfs(curr, lvl + 1, res);
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;

        dfs(root, 0, res);

        return res;
    }
};