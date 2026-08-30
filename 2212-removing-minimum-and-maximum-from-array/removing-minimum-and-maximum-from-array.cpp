class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int max_idx = -1;
        int min_idx = -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0; i<n; i++){
            if(maxi<nums[i]){
                max_idx = i;
                maxi = nums[i];
            }
        }
        for(int i = 0; i<n; i++){
            if(mini>nums[i]){
                min_idx = i;
                mini = nums[i];
            }
        }
        int case_1 = max(max_idx+1, min_idx+1); //both front
        int case_2 = n - min(max_idx,min_idx); //both back
        int case_3 = min(min_idx + 1 + n - max_idx,n - min_idx + max_idx+1);//back + front

        return min(case_3,min(case_2,case_1));
    }
};