class StockSpanner {
public:
    vector<int> res;
    StockSpanner() {}

    int next(int price) {
        res.push_back(price);

        int n = res.size();
        int ans = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (price >= res[i])
                ans++;
            else break;
        }

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */