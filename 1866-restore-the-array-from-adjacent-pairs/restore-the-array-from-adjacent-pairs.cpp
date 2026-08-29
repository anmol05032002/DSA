class Solution {
public:
    void dfs(int start , int prev,unordered_map<int,vector<int>>&adj,vector<int> &ans){
        ans.push_back(start);

        for(int &v: adj[start]){
            if(v!=prev){
                dfs(v,start,adj,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int,vector<int>>adj;
        
        for(auto vec: adjacentPairs){
             int u = vec[0];
             int v = vec[1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }

       int startPoint = -1;
        
        for(auto &it : adj) {
            if(it.second.size() == 1) {
                startPoint = it.first;
                break;
            }
        }
        dfs(startPoint, INT_MIN, adj,ans);  
        return ans;


    }
};