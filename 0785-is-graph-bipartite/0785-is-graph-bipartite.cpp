class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& colors, int node, int clr,
             int& res) {
        colors[node] = clr;

        for (auto curr : graph[node]) {
            if (colors[curr] != -1 && colors[curr] == clr) {
                res = false;
                return;
            }
            if (colors[curr] == -1)
                dfs(graph, colors, curr, !clr, res);
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), -1);
        int res = true;
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] == -1)
                dfs(graph, colors, i, 1, res);
        }

        return res;
    }
};