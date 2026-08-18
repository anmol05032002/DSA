class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n  = nums.size();
        unordered_map<int,int>mp;

        int i =0;
        int j = 0;

        // while(j<n){
        //     if(j-i+1<=k)
        //     {
        //       mp[nums[j]]++;
        //       j++;
        //     }
        //     else{
        //         i++;
        //         j = i;
        //     }

        // }

        // int maxi = -1;
        bool present = false;

        // for(auto it:mp){
        //     int a = it.first;
        //     int b = it.second;
        //     if(b==1){
        //         present = true;
        //         maxi = max(maxi,a);
        //     }
        // }

        int maxm = -1;
        int ans = -1;

        for(int i=0; i<n; i++){
            maxm = max(maxm,nums[i]);
        }

        if(k==n)return maxm;

        // else if(present)return maxi;

       

     while(i<n){
            mp[nums[i]]++;
            i++;
        }
         for(auto it:mp){
            int a = it.first;
            int b = it.second;
                if(b==1){
                    present = true;
                    ans = max(ans,a);
                }
        }
       
       if(k==1 && present)return ans;
       
       int first = mp[nums[0]];
       int last = mp[nums[n-1]];

       if(k!=1 && k!=n){
           if(first!=1 && last ==1){
            return nums[n-1];
           }
           else if(first==1 && last!=1){
            return nums[0];
           }
           else if(first==1 && last==1){
            return max(nums[0],nums[n-1]);
           }
       }
        return -1;
    }
};