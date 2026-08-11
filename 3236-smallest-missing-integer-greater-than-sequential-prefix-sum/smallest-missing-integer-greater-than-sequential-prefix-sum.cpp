class Solution {
public:

// int summ(int i, int j,vector<int>& nums){
//     int sum = 0;

//     for(int x =i; x<=j; x++){
//         sum+=nums[x];
//     }

//     return sum;
// }

//  bool find(int num, vector<int>& nums){
//     for(int i=0; i<nums.size(); i++){
//         if(nums[i]==num){
//             return true;
//         }
//     }
//     return false;
//  }
    int missingInteger(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1)return nums[0]+1;

    //     int i =0;
    //     int start = 0;
    //     int j = 0;

    //     int sum = 0;
    //     int maxi = 0;
    //     pair<int,int> idx;
    //     unordered_map<int,pair<int,int>>mp;

    //     while(j<n-1){
    //      if(nums[j+1]-nums[j]==1){
    //         // sum+=nums[j];
    //         // j++;
    //         // if(j==n-1){
    //         //     // mp.insert({j-i+1,{i,j}});
    //         // }
    //      }
    //      else{
    //         // int x = summ(i,j,nums);
    //         int count = j-i+1;
    //     //    maxi = max(count,maxi);
    //     // mp.insert({count,{i,j}});
    //     //    j++;
    //        i=j;
    //      }
    //      mp.insert({j-i+1,{i,j}});
    //      j++;
    //     }
    //        int s =0;
    //        int R_sum = INT_MAX;
    //     for(auto it:mp){
    //         int c = it.first;
    //         int i = it.second.first;
    //         int j = it.second.second;

    //         if(c>=maxi){
    //             maxi = c;
    //           s = summ(i,j,nums);
    //           R_sum = min(R_sum,s);
    //         }
    //     }
       



    //    int maxm = 0;

    //    for(int i=0; i<n; i++){
    //     maxm =  max(nums[i],maxm);
    //    }

    //    while(R_sum<=maxm){
    //     if(find(R_sum,nums)){
    //         R_sum++;
    //     }
    //     else{
    //         break;
    //     }
    //    }
    //  return R_sum;
        int n = nums.size();

        // Find the sum of the longest sequential prefix
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } 
            else {
                break;
            }
        }

        // Find the smallest missing integer >= sum
        while (find(nums.begin(), nums.end(), sum) != nums.end()) {
            sum++;
        }

        return sum;
    }

};