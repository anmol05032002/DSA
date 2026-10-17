class Solution {
public:

    int digit_sum(int num){
        int sum = 0;

        while(num!=0){
            int d = num%10;
            sum+=d;
            num/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
       vector<pair<int,int>> store;

        int n  = nums.size();

        for(int i =0; i<n; i++){
            int sum = digit_sum(nums[i]);
            store.push_back({sum,nums[i]});
        }

        sort(store.begin(),store.end());

        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[store[i].second]=i;
        }
        int swaps = 0;
         for (int i = 0; i < n; i++) {
               while (mp[nums[i]] != i) {
                 swap(nums[i], nums[mp[nums[i]]]);
                 swaps++;
                }
            }
    return swaps;
    }
};