class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        long long product1 = (long long)nums[n-1] * nums[n-2] * nums[n-3];  
        long long product2 = (long long)nums[0] * nums[1] * nums[n-1];
        
        return max(product1, product2);
    }
};