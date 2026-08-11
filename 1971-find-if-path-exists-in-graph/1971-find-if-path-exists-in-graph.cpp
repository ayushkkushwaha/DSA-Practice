class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {

        vector<vector<int>> adjList(n);

        for (auto curr : edges) {
            int u = curr[0];
            int v = curr[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == dest)
                return true;

            for (auto j : adjList[curr]) {
                if (!visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }

        return false;
    }
};