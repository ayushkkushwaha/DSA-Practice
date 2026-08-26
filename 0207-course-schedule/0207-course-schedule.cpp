class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);
        for (auto curr : prerequisites) {
            int src = curr[0];
            int dest = curr[1];
            adj[src].push_back(dest);
            inDeg[dest]++;
        }

        vector<int> res;
        queue<int> q;
        for (int i = 0; i < inDeg.size(); i++) {
            if (inDeg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (auto i : adj[curr]) {
                inDeg[i]--;
                if (inDeg[i] == 0)
                    q.push(i);
            }
        }

        if (res.size() == numCourses)
            return true;

        return false;
    }
};