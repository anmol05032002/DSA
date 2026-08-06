class Solution {
public:

    bool check(int n, int t) {
        long long product = 1;

        while (n != 0) {
            long long d = n % 10;
            product *= d;
            n /= 10;
        }

        return product % t == 0;
    }

    int smallestNumber(int n, int t) {

        for (int i = n; ; i++) {
            if (check(i, t)) {
                return i;
            }
        }

        return -1; 
    }
};