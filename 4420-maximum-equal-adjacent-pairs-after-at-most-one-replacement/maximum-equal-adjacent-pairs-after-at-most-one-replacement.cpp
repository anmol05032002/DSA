class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,int>,int> mp;

        int cnt = 0;
        int mx =0;

        for(int i =0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                cnt++;
            }
            else{
                mp[{nums[i], nums[i+1]}]++;
                mp[{nums[i+1], nums[i]}]++;

            }
        }
        for(auto it : mp)
            mx = max(mx, it.second);

            return cnt + mx;

    }
};