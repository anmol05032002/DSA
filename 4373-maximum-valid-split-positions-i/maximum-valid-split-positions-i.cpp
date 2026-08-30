class Solution {
public:
   
    int score(const vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;

        vector<int> prefixGCD(n), suffixGCD(n);
        prefixGCD[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefixGCD[i] = gcd(prefixGCD[i - 1], arr[i]);

        suffixGCD[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffixGCD[i] = gcd(suffixGCD[i + 1], arr[i]);

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            if (prefixGCD[i] == suffixGCD[i + 1])
                ans++;

        return ans;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = score(nums);   // case: remove nothing

        vector<int> arr;
        arr.reserve(n - 1);      // avoid reallocating every iteration
        for (int remove = 0; remove < n; remove++) {
            arr.clear();
            for (int i = 0; i < n; i++)
                if (i != remove) arr.push_back(nums[i]);
            ans = max(ans, score(arr));
        }
        return ans;
    }
};