class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> dest(n, 1e8);
        dest[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dest;
            for (auto flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int w = flight[2];

                if (dest[s] != 1e8 && dest[s] + w < temp[d])
                    temp[d] = dest[s] + w;
            }

            dest = temp;
        }

        return dest[dst] != 1e8 ? dest[dst] : -1;
    }
};