class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {


        //   // Approach - 01
        // just sort the array and find
        vector<int> ans;
        int n  = nums.size();

        int count = 0;

        for(int i =0; i<n; i++){
            if(nums[i]<target){
                count++;
            }
        }
           // Approach - 02
        // bool first_time = false;
        // for(int i =0; i<n; i++){
        //     if(!first_time && nums[i]==target){
        //         ans.push_back(count);
        //         count++;
        //         first_time = false;
        //     }
        //    else if(nums[i]==target){
        //         ans.push_back(count);
        //         count++;
        //     }
        // }

        // Approach - 03
        int freq = 0;

        for(int i =0; i<n; i++){
            if(nums[i]==target){
                freq++;
            }
        }

        for(int i = count; i<count+freq; i++){
            ans.push_back(i);
        }
        return ans;
    }
};