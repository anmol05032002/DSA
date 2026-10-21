class Solution {
public:

    bool sorted(string &s){
        int n = s.length();
        for(int i =0; i<n-1; i++){
            if(s[i]-'a' > s[i+1]-'a'){
                return false;
            }
        }
        return true;

    }
    int minOperations(string s) {
        // return 3;
        int n  = s.length();
        if(sorted(s))return 0;
        if(!sorted(s) && n==2)return -1;

        // pair<int,int> largest_idx = {-1,-1};
        // pair<int,int> smallest_idx = {-1,-1};
        int largest_idx = -1;
      int  smallest_idx = -1;

        char maxi = 'a';
        char mini = 'z';

        for(int i =0; i<n; i++){
            if(s[i]>maxi){
                maxi = s[i];
            }
            if(s[i]<mini){
                mini = s[i];
            }
        }

        for(int i =0;  i<n; i++){
            if(maxi==s[i]){
                largest_idx= i;
            }
        }
        

        for(int i =n-1;  i>=0; i--){
            if(mini==s[i]){
                smallest_idx = i;
            }
        }
        // for(int i =n-1;  i>=0; i--){
        //     if(mini==s[i]){
        //         smallest_idx.second = i;
        //         // break;
        //     }
        // }
         
         if(largest_idx==0 && smallest_idx==n-1)return 3;
         if(smallest_idx==0) return 1;
         if(largest_idx==n-1) return 1;
         else return 2;


    }
};