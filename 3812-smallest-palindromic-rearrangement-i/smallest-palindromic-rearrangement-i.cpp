class Solution {
public:

  void reverse(string &s){
    int n = s.length();

    int i =0;
    int j = n-1;

    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
  }
    string smallestPalindrome(string s) {
        string first_half = "";
        int n = s.length();

        if(n==1)return s;

        int mid = n/2;

        char middle = s[mid];

        for(int i =0; i<n/2; i++){
            first_half.push_back(s[i]);
        }

        sort(first_half.begin(),first_half.end());
        // return first_half + middle;

        string rev = first_half;

        reverse(rev);

        string ans = "";

        if(n%2)
       ans =  first_half + middle + rev;
       else
       ans = first_half + rev;
       
       return ans;


    }
};