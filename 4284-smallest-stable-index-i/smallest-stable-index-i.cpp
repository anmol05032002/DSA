class Solution {
public:
    int minm(vector<int>& nums, int idx){
        int mini = INT_MAX;
        for(int i = idx; i<nums.size(); i++){
            mini = min(mini,nums[i]);
        }
        return mini;
    }
    int maxm(vector<int>& nums, int idx){
        int maxi = INT_MIN;
        for(int i = 0; i<=idx; i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        for(int i=0; i<n; i++){
            int mx = maxm(nums,i);
            int mn = minm(nums,i);

            if(mx - mn <=k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};