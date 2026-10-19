class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();

        int i =0; 
        int j = 1;
        int ans = 0;

        while(j<n){
            if((nums[i]^nums[j])==0){
                ans++;
                j++;
            }
            else{
             i=j;
             j++;
            }
        }
        return ans;
    }
};