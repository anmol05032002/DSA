class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for(int num : nums)
            total += num;

        int target = total - x;

        if(target == 0)
            return n;

        int i = 0;
        int sum = 0;
        int maxi = -1;

        for(int j = 0; j < n; j++) {
            sum += nums[j];

            while(i <= j && sum > target) {
                sum -= nums[i];
                i++;
            }

            if(sum == target) {
                maxi = max(maxi, j - i + 1);
            }
        }

        if(maxi == -1)
            return -1;

        return n - maxi;
    }
};