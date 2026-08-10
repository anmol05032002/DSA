class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;

        int n = nums1.size();
        int m = nums2.size();
         int i =0;
         int j =0;

         while(i<n && j<m){
            int a = nums1[i][0];
            int b = nums2[j][0];
            vector<int> num;
            int sum = 0;
            if(a==b){
                 sum = nums1[i][1] + nums2[j][1];
                 num.push_back(a);
                num.push_back(sum);
                i++;
                j++;
            }
            else if(a>b){
                 sum = nums2[j][1];
                 num.push_back(b);
                 j++;
                  num.push_back(sum);
            }
            else{
                 sum = nums1[i][1];
                 num.push_back(a);
                 i++;
                  num.push_back(sum);
            }
            ans.push_back(num);
         }


        
            
            while(i<n){
                vector<int> v;
               int id = nums1[i][0];
               int num = nums1[i][1];
               v.push_back(id);
               v.push_back(num);
               ans.push_back(v);
               i++;
            }
         

          
            while(j<m){
                vector<int> v;
               int id = nums2[j][0];
               int num = nums2[j][1];
               v.push_back(id);
               v.push_back(num);
               ans.push_back(v);
               j++;
            }
         
         return ans;
    }
};