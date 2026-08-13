class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj;
        int nodes = isConnected.size();

        vector<bool> visited(nodes, false);

        for (int i = 0; i < nodes; i++)
            adj.push_back({});

        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (i != j && isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < nodes; i++) {
            if (!visited[i]) {
                res++;
                dfs(adj, i, visited);
            }
        }

        return res;
    }

    void dfs(vector<vector<int>> adj, int src, vector<bool>& visited) {
        visited[src] = true;

        for (auto i : adj[src]) {
            if (!visited[i]) {
                dfs(adj, i, visited);
            }
        }
    }
};