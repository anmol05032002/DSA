class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        // return 1;
        int n = nums.size();
        vector<int> srt = nums;
        sort(srt.begin(),srt.end());
        int count = 0;
       int bit = -1;
       bool sorted = true;
        for(int i =0; i<n; i++){
            if(srt[i]==nums[i])continue;
            bit &= (nums[i] & srt[i]);
            sorted = false;
            // count = max(count,bit_and);
        }
        if(!sorted)return bit;
        return 0;



    }
};