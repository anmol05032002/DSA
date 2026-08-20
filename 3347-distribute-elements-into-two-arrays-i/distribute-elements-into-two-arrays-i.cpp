class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        int first = nums[0];
        int second = nums[1];
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(first);
        arr2.push_back(second);

        int i =2;

        while(i<n){
            if(first>second){
                arr1.push_back(nums[i]);
                first = nums[i];
            }
            else{
                arr2.push_back(nums[i]);
                second = nums[i];
            }
            i++;
        }


        for(int i =0; i<arr1.size(); i++){
            ans.push_back(arr1[i]);
        }

        for(int i =0; i<arr2.size(); i++){
            ans.push_back(arr2[i]);
        }
        return ans;
    }
};