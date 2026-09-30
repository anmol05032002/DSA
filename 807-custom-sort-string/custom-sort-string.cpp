class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.length();
        int m = s.length();

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(int i =0; i<n; i++){
            mp1[order[i]] = i;
        }

        vector<pair<int,char>> v;
        for(int i =0; i<m; i++){
            char c = s[i];
            if(mp1.find(c)!=mp1.end()){
                // mp2[s[i]]=mp1[s[i]];
                v.push_back({mp1[s[i]],s[i]});
            }
            else{
                v.push_back({-1,s[i]});
                // mp2[s[i]] = -1;
            }
        }

   

        // for(auto it: mp2){
        //    char c = it.first;
        //    int num = it.second;
        //    v.push_back({num,c});
        // }

        // cout<<v.size();
        sort(v.begin(),v.end());

        string ans = "";

        for(auto it : v){
            // cout<<it.second<<" ";
            ans.push_back(it.second);
        }  
        return ans;    
    }
};