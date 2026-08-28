class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = 0; i<n; i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]++;
            }
            else{
                ans+=mp[nums[i]]++;
            }
        }
        return ans;
    }
};