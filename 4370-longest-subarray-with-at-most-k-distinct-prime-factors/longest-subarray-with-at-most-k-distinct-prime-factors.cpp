class Solution {
public:
    vector<int> getPrimeFactors(int n) {
        vector<int> factors;
        if (n % 2 == 0) {
            factors.push_back(2);
            while (n % 2 == 0) n /= 2;
        }
        for (int y = 3; y * y <= n; y += 2) {
            if (n % y == 0) {
                factors.push_back(y);
                while (n % y == 0) n /= y;
            }
        }
        if (n > 2) factors.push_back(n);
        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> prime_freq;
        int i = 0, j = 0, maxi = 0;
        
        while (j < nums.size()) {
            vector<int> right_factors = getPrimeFactors(nums[j]);
            for (int prime : right_factors) {
                prime_freq[prime]++;
            }
            
            while (prime_freq.size() > k) {
                vector<int> left_factors = getPrimeFactors(nums[i]);
                for (int prime : left_factors) {
                    prime_freq[prime]--;
                    if (prime_freq[prime] == 0) {
                        prime_freq.erase(prime);
                    }
                }
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};