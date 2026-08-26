class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Build directed weighted adjacency list.
        // times[i] = {src, dest, time}
        // means signal takes 'time' units to travel from src -> dest.
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto curr : times) {
            int src = curr[0];
            int dest = curr[1];
            int time = curr[2];

            adj[src].push_back({dest, time});
        }

        // Min-heap storing {shortest distance, node}.
        // Node with the smallest known distance is processed first.
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        // Source node k starts with distance 0.
        pq.push({0, k});

        // dist[i] = shortest time required to reach node i from k.
        // INT_MAX means node i has not been reached yet.
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Dijkstra's algorithm
        while (!pq.empty()) {

            // Get the node with the smallest current distance.
            pair<int, int> curr = pq.top();
            pq.pop();

            int d = curr.first;
            int node = curr.second;

            // Ignore outdated entries in the priority queue.
            // A shorter distance to this node has already been found.
            if (dist[node] < d)
                continue;

            // Try to improve the shortest distance of every neighbour.
            for (auto i : adj[node]) {

                int neigh = i.first;
                int neighDist = i.second + d;

                // If going through 'node' gives a shorter path,
                // update the neighbour's shortest distance.
                if (neighDist < dist[neigh]) {
                    dist[neigh] = neighDist;

                    // Push the updated distance into the min-heap.
                    pq.push({neighDist, neigh});
                }
            }
        }

        // The network delay is the time taken by the last node
        // to receive the signal, i.e. the maximum shortest distance.
        int res = 0;

        for (int i = 1; i <= n; i++) {

            // If any node is unreachable from k,
            // the signal cannot reach the entire network.
            if (dist[i] == INT_MAX)
                return -1;

            res = max(res, dist[i]);
        }

        return res;
    }
};