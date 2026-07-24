class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        unordered_map<char, int> ref;
        unordered_map<char, int> curr;

        vector<int> res;

        for (int i = 0; i < p.size(); i++) {
            ref[p[i]]++;
            curr[s[i]]++;
        }

        int i = 0;
        int j = p.size();

        if (ref == curr)
            res.push_back(0);

        while (j < s.size()) {

            curr[s[i]]--;
            curr[s[j++]]++;

            if (curr[s[i]] == 0)
                curr.erase(s[i]);

            i++;

            if (ref == curr)
                res.push_back(i);
        }

        return res;
    }
};