class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            for (auto j : rooms[i]) {
                adj[i].push_back(j);
            }
        }

        queue<int> q;

        int src = 0;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto i : adj[curr]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        for (auto i : visited)
            if (!i)
                return false;

        return true;
    }
};