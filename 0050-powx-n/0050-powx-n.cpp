class Solution {
public:
    double powF(double x, long N) {

        // base cond
        if (N == 0)
            return 1;

        if (N % 2 == 0) {

            return powF(x * x, N / 2);
        }

        return x * powF(x * x, N / 2);
    }

    double myPow(double x, int n) {

        long N = n;

        if (N < 0) {
            N = -N;
            return 1 / powF(x, N);
        } else
            return powF(x, N);
    }
};