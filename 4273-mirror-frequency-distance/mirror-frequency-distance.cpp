class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
        }
        // return s[2]-'0';

        vector<bool> char_vis(26,true);
        vector<bool>digit_vis(10,true);
        int ans = 0;

        for(int i=0; i<n; i++){
            if(s[i]>='a' && s[i]<='z'){
                int freq_c = mp[s[i]];
                char complement = 'z' - (s[i]-'a');
                int freq_m = mp[complement];
                if(char_vis[s[i]-'a'] || char_vis[complement-'a']){
                    ans+= abs(freq_c-freq_m);
                    char_vis[s[i]-'a']=false;
                    char_vis[complement-'a']=false;
                }
                
            }
            else if(s[i]>='0' && s[i]<='9'){
                int freq_c = mp[s[i]];
                char complement = '9' - (s[i]-'0');
                int freq_m = mp[complement];
                if(digit_vis[s[i]-'0'] || digit_vis[complement-'0']){
                    ans+= abs(freq_c-freq_m);
                    digit_vis[s[i]-'0']=false;
                    digit_vis[complement-'0']=false;
                }
            }

        }
        return ans;
    }
};