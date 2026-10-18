class Solution {
    vector<vector<long long>> dp;
    long long MOD = 1e9 + 7;
public:
   long long countWays(vector<int> &nums) {
        if (nums.size() <= 1) return 1;
        vector<int> left, right;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[0]) right.push_back(nums[i]);
            else left.push_back(nums[i]);
        }
        int leftSize = left.size(), rightSize = right.size();
        return countWays(left) * countWays(right) % MOD * dp[leftSize + rightSize][leftSize] % MOD;
    }


    int numOfWays(vector<int> &nums) {
        dp = vector<vector<long long>>(nums.size() + 1, vector<long long>(nums.size() + 1, 0));
        for (int i = 1; i < nums.size() + 1; ++i) {
            dp[i][0] = 1;
            dp[i][1] = i;
            dp[i][i - 1] = i;
            dp[i][i] = 1;
        }
        for (int i = 2; i < nums.size() + 1; ++i) {
            for (int j = 2; j < nums.size() + 1; ++j) {
                if (i >= j) dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
                else break;
            }
        }
        return countWays(nums) - 1;
    }
};