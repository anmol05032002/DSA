class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        int smallest = nums[0];
      vector<int> ans;
        for(int i =0; i<n; i++){
            if(nums[i]==(smallest + i)) continue;
            else{
                int x = nums[i-1];
                int y = nums[i];
                for(int j = x+1; j<y; j++)
                ans.push_back(j);
            }
        }
        return ans;
    }
};