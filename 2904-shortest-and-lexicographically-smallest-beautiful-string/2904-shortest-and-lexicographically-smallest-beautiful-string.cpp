class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        string res = "";

        int ones = 0;
        int n = s.size();

        int left = 0;
        int right = 0;

        while (right < n) {

            // Expand window.
            if (s[right] == '1')
                ones++;

            right++;

            // Once we have k ones, try to minimize the window.
            while (ones == k) {

                string temp = s.substr(left, right - left);

                // Update answer if:
                // 1. Current substring is shorter, or
                // 2. Same length but lexicographically smaller.
                if (res.empty() ||
                    temp.size() < res.size() ||
                    (temp.size() == res.size() && temp < res)) {
                    res = temp;
                }

                // Shrink window from the left.
                if (s[left] == '1')
                    ones--;

                left++;
            }
        }

        return res;
    }
};