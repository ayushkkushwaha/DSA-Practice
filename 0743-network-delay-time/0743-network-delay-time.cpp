class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto curr : times) {
            int src = curr[0];
            int dest = curr[1];
            int times = curr[2];

            adj[src].push_back({dest, times});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            int d = curr.first;
            int node = curr.second;

            if (dist[node] < d)
                continue;

            for (auto i : adj[node]) {
                int neigh = i.first;
                int neighDist = i.second + d;

                if (neighDist < dist[neigh]) {
                    dist[neigh] = neighDist;
                    pq.push({neighDist, neigh});
                }
            }
        }

        int res = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;

            res = max(res, dist[i]);
        }

        return res;
    }
};