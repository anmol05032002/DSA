class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // vector<int> ans;
        int n = nums.size();

        int i =0;
        int j = 1;

        while(i<n && j<n){
            if(nums[i]%2==0){
                i+=2;
            }
           else if(nums[j]%2){
                j+=2;
            }
            else{
                swap(nums[i],nums[j]);
                i+=2;
                j+=2;
            }
        }

        // for(auto i: nums){
        //     ans.push_back(i);
        // }
        return nums;
    }
};