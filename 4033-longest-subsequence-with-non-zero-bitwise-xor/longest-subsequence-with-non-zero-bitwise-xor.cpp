class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0;
        // sort(nums.begin(),nums.end());

        bool non_zero = false;

        for(int i=0; i<n; i++){
          if(nums[i]!=0){
            non_zero = true;
            break;
          }
        }

        for(int i=0; i<n; i++){
            xorr^=nums[i];
        }
        unordered_set<int> s;
       if(xorr!=0)return n;

       else if(xorr==0){
        
            for(auto i:nums){
            s.insert(i);  
              }
       }

        if(s.size()!=1 || (s.size()==1 && non_zero)){
                return n-1;
            }
            else {
                return 0;
            }
        
    }
};