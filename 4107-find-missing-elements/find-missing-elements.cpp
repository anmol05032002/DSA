class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

    //     sort(nums.begin(),nums.end());
    //     int smallest = nums[0];
      vector<int> ans;
    //     for(int i =0; i<n; i++){
    //         if(nums[i]==(smallest + i)) continue;
    //         else{
    //             int x = nums[i-1];
    //             int y = nums[i];
    //             for(int j = x+1; j<y; j++)
    //             ans.push_back(j);
    //         }
    //     }


    int maxi = INT_MIN;
     for(int i=0; i<n; i++){
        maxi = max(maxi,nums[i]);
     }

     int mini = INT_MAX;
     for(int i=0; i<n; i++){
        mini = min(mini,nums[i]);
     }

     unordered_map<int,bool>mp;

     for(int i = 0; i<n; i++){
        mp[nums[i]] = true;
     }


     for(int i = mini; i<=maxi; i++){
        if(mp[i]){
            continue;
        }
        else{
            ans.push_back(i);
        }
     }
        return ans;
    }
};