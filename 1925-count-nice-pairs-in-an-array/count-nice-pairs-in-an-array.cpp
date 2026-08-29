class Solution {
public:
 const long long MOD = 1e9 + 7;
   int reverse(int n){
      int rev = 0;
      while (n > 0) {
         rev = rev * 10 + n % 10;
         n /= 10;
       }
      return rev;
}
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            nums[i] = nums[i]-reverse(nums[i]);
        }

        for(int i =0; i<n; i++){
            int num = nums[i];
            if(mp.find(num)==mp.end()){
                mp[num]=1;
            }
            else{
                ans=(ans+mp[num]++)%MOD;
            }
        }
          return ans;
    }
};