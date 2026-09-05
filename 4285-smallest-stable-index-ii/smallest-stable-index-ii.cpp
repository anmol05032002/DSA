class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> PrefixMin(n);

        PrefixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            PrefixMin[i] = min(PrefixMin[i + 1], nums[i]);
        }

        int maxi = -1;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            if (maxi - PrefixMin[i] <= k) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};