class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Build adjacency list:
        // prerequisites = [dest, src] means:
        // src -> dest, i.e. src must be completed before dest.
        vector<vector<int>> adj(numCourses);

        // inDeg[i] = number of prerequisites required before course i.
        vector<int> inDeg(numCourses, 0);

        for (auto curr : prerequisites) {
            int dest = curr[0];
            int src = curr[1];

            // Add dependency edge: src -> dest
            adj[src].push_back(dest);

            // dest has one more prerequisite.
            inDeg[dest]++;
        }

        vector<int> res;
        queue<int> q;

        // Courses with indegree 0 have no remaining prerequisites,
        // so they can be completed immediately.
        for (int i = 0; i < inDeg.size(); i++) {
            if (inDeg[i] == 0)
                q.push(i);
        }

        // Kahn's Algorithm (BFS-based Topological Sort)
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Course is successfully completed.
            res.push_back(curr);

            // Completing curr removes one prerequisite
            // from every course that depends on curr.
            for (auto i : adj[curr]) {

                // One prerequisite of course i is now completed.
                inDeg[i]--;

                // If no prerequisites remain, course i can now be completed.
                if (inDeg[i] == 0)
                    q.push(i);
            }
        }

        // If every course was processed, there is no cycle.
        // If some courses remain, they are part of a dependency cycle.
        return res.size() == numCourses;
    }
};