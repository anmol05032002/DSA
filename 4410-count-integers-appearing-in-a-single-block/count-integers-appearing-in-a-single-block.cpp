class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        unordered_set<int> seen;
        unordered_set<int> bad;

        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                if (seen.count(nums[i])) {
                    bad.insert(nums[i]);
                }

                seen.insert(nums[i]);
            }
        }

        return seen.size() - bad.size();
    }
};