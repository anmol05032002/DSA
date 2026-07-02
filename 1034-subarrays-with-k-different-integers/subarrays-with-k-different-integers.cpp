class Solution {
public:
  
     int atMost(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int left = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++) {

        // New distinct element
        if (freq[nums[right]] == 0)
            k--;

        freq[nums[right]]++;

        // Too many distinct elements
        while (k < 0) {
            freq[nums[left]]--;

            if (freq[nums[left]] == 0)
                k++;

            left++;
        }

        // Count all valid subarrays ending at 'right'
        ans += (right - left + 1);
    }

    return ans;
}
    bool Isvalid(vector<int>& nums, int i, int j , int k){
        set<int>s;
        for(int x = i; x<=j; x++){
            s.insert(nums[x]);
        }
        if(s.size()==k)return true;
        return false;
    }

    bool Over(vector<int>& nums, int i, int j , int k){
        set<int>s;
        for(int x = i; x<=j; x++){
            s.insert(nums[x]);
        }
        if(s.size()>k)return true;
        return false;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        // int cnt =0;

        // for(int i =0; i<n; i++){
        //     for(int j = i; j<n; j++){
        //         if(Isvalid(nums,i,j,k)){
        //             cnt++;
        //         }
        //         if(Over(nums,i,j,k)){
        //             break;
        //         }
        //     }
        // }
       
//       int ans = 0;

// for (int i = 0; i < n; i++) {
//     // unordered_map<int,int> freq;
//     // int distinct = 0;

//     // for (int j = i; j < n; j++) {

//     //     if (freq[nums[j]] == 0)
//     //         distinct++;

//     //     freq[nums[j]]++;

//     //     if (distinct == k)
//     //         ans++;
//     //     else if (distinct > k)
//     //         break;
//     // }
    
// }
 return atMost(nums, k) - atMost(nums, k - 1);
}
    
};