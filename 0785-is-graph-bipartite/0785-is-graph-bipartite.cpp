class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& colors, int node, int clr,
             bool& res) {

        // Assign the current node a color.
        // We use only two colors: 0 and 1.
        colors[node] = clr;

        for (auto curr : graph[node]) {

            // If the neighbour already has the same color,
            // then two adjacent nodes have the same color,
            // so the graph is NOT bipartite.
            if (colors[curr] != -1 && colors[curr] == clr)
                res = false;

            // If the neighbour has not been colored yet,
            // assign it the opposite color and continue DFS.
            if (colors[curr] == -1)
                dfs(graph, colors, curr, !clr, res);
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {

        // -1 = not colored
        //  0 = color 0
        //  1 = color 1
        vector<int> colors(graph.size(), -1);

        bool res = true;

        // Graph may contain multiple disconnected components,
        // so start DFS from every uncolored node.
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] == -1)
                dfs(graph, colors, i, 1, res);
        }

        return res;
    }
};