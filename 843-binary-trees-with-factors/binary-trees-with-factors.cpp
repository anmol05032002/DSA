class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const long long MOD = 1e9 + 7;

        sort(arr.begin(), arr.end());

        int n = arr.size();

        unordered_map<long long, long long> mp;

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            mp[arr[i]] = 1;

            for (int j = 0; j < i; j++) {

                int LC = arr[j];

                if (arr[i] % LC == 0) {

                    int RC = arr[i] / LC;

                    if (mp.find(RC) != mp.end()) {

                        mp[arr[i]] =
                            (mp[arr[i]] +
                             mp[LC] * mp[RC]) % MOD;
                    }
                }
            }

            // ans = (ans + mp[arr[i]]) % MOD;
        }
        for (auto it: mp){
            ans= (ans+ it.second)%MOD;
        }

        return ans;
    }
};