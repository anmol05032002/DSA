class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26,0);

        for(int i =0; i<n; i++){
            int x = word[i]-'a';
            freq[x]++;
        }

        int ans = 0;
        sort(freq.begin(),freq.end(),greater<int>());
       
        for(int i=0; i<26; i++){
            int frq = freq[i];
            int press = frq * (i/8 +1);
            ans+=press;
        }
          return ans;
    }
};