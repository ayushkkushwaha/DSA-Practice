class Solution {
public:
    int reverse(int x) {
        int isNeg = 1;
        long long temp = x;
        
        if (x < 0) {
            isNeg = -1;
            temp = x * -1LL;
        }

        string s = to_string(temp);

        int l = 0, r = s.size() - 1;

        while (l <= r)
            swap(s[l++], s[r--]);
        temp = stoll(s) * isNeg;

        if (temp > INT_MAX || temp < INT_MIN)
            return 0;
        
        return static_cast<int>(temp);
    }
};