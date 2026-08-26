class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.length();
        int count = 0;
        stringstream ss(s);
        string word;
        vector<string> words;
  
       while (ss >> word) {
        words.push_back(word);
        count++;
      }
        if(n!=count)return false;
        set<char>used;

        unordered_map<string,char>mp;
        for(int i=0; i<n; i++){
            if(mp.find(words[i])==mp.end() && used.find(pattern[i])==used.end()){
               mp[words[i]] = pattern[i];
               used.insert(pattern[i]);
            }
            else if(mp[words[i]]!=pattern[i]){
               return false;
            }

        }
        return true;
   }
};