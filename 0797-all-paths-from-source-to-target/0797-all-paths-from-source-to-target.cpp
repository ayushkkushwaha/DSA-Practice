class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int src,
             vector<int> temp, vector<vector<int>>& res, int dest) {
        visited[src] = true;
        temp.push_back(src);

        if (src == dest) {
            res.push_back(temp);
        }

        for (auto i : adj[src]) {
            if (!visited[i]) {
                dfs(adj, visited, i, temp, res, dest);
            }
        }

        visited[src] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            for (auto j : graph[i])
                adj[i].push_back(j);
        }

        dfs(adj, visited, 0, {}, res, n - 1);

        return res;
    }
};