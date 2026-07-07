class Solution {
public:
    long long sumAndMultiply(int n) {
        long long temp = 0;
        long long sum = 0;

        while (n != 0) {
            int d = n % 10;
            sum += d;

            if (d != 0)
                temp = temp * 10 + d;

            n /= 10;
        }

        long long num = 0;
        while (temp != 0) {
            num = num * 10 + temp % 10;
            temp /= 10;
        }

        return num * sum;
    }
};