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
    void helper(Node* root, vector<int>& res) {
        // If the current node is NULL, stop the recursion
        if (!root)
            return;

        // Add the current node's value to the result
        res.push_back(root->val);

        // Traverse all children of the current node
        for (auto curr : root->children) {
            // Recursively visit each child
            helper(curr, res);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};