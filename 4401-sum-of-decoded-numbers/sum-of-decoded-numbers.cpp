class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long x, long long y) {
        long long ans = 1;

        x %= MOD;

        while (y > 0) {
            if (y % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }

    long long solve(long long n) {
        int w = n % 10;

        long long d = n / 10;
        int no_digit = 0;
        long long temp = d;

        while (temp != 0) {
            temp /= 10;
            no_digit++;
        }
        long long div = 1;

        for (int i = 0; i < no_digit - w; i++) {
            div *= 10;
        }

        long long x = d / div;
        long long y = d % div;

        return power(x, y);
    }

    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + solve(nums[i])) % MOD;
        }

        return sum;
    }
};