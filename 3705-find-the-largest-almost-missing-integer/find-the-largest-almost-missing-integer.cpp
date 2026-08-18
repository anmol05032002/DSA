class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n  = nums.size();
        unordered_map<int,int>mp;

        int i =0;
        int j = 0;

        while(j<n){
            if(j-i+1<=k)
            {
              mp[nums[j]]++;
              j++;
            }
            else{
                i++;
                j = i;
            }

        }

        int maxi = -1;
        bool present = false;

        for(auto it:mp){
            int a = it.first;
            int b = it.second;
            if(b==1){
                present = true;
                maxi = max(maxi,a);
            }
        }

        int maxm = -1;

        for(int i=0; i<n; i++){
            maxm = max(maxm,nums[i]);
        }

        if(k==n)return maxm;

        else if(present)return maxi;

        return -1;
    }
};