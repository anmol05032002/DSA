class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int size = nums.size();

        for(int i =0; i<size; i++){
            int complement = target - nums[i];

            if(mp.find(complement)!=mp.end()){
                return {i,mp[complement]};
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};