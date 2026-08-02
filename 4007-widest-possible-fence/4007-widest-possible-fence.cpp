class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        map<int, int> st;

        // Frequency of original planks
        for (auto i : planks)
            st[i]++;

        vector<pair<int, int>> temp;

        for (auto i : st)
            temp.push_back({i.first, i.second});

        // Stores maximum fence width for each height
        map<int, int> width = st;

        for (int i = 0; i < temp.size(); i++) {

            // Handle same height pair (a + a)
            if (temp[i].second >= 2)
                width[2 * temp[i].first] += temp[i].second / 2;

            // Handle different heights
            for (int j = i + 1; j < temp.size(); j++) {
                width[temp[i].first + temp[j].first] +=
                    min(temp[i].second, temp[j].second);
            }
        }

        int maxi = 0;

        for (auto i : width)
            maxi = max(maxi, i.second);

        return maxi;
    }
};