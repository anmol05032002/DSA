class Solution {
public:
    const long long MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> ans;

        vector<long long> prefixSum(n);   // digit sum prefix
        vector<long long> prefixNum(n);   // number skipping zeros prefix
        vector<int>       nonZero(n);     // count of non-zero digits prefix
        vector<long long> pow10(n + 1);   // pow10[i] = 10^i % MOD

        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = pow10[i-1] * 10 % MOD;

        long long sumVal = 0, numVal = 0;
        int nzCount = 0;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            sumVal += d;
            prefixSum[i] = sumVal % MOD;

            nzCount += (d != 0);
            nonZero[i] = nzCount;

            numVal = (d != 0) ? (numVal * 10 + d) % MOD : numVal;
            prefixNum[i] = numVal;
        }

        for (auto& q : queries) {
            int x = q[0], y = q[1];

            // O(1) digit sum
            long long sum = prefixSum[y] - (x > 0 ? prefixSum[x-1] : 0);
            sum = ((sum % MOD) + MOD) % MOD;

            // O(1) number with zeros skipped
            int nz = nonZero[y] - (x > 0 ? nonZero[x-1] : 0);  // non-zero digits in [x..y]
            long long num = prefixNum[y];
            if (x > 0)
                num = (num - prefixNum[x-1] * pow10[nz] % MOD + MOD) % MOD;

            ans.push_back((int)((sum * num) % MOD));
        }

        return ans;
    }
};