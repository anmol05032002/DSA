class Solution {
public:
void dfs(unordered_map<int,vector<int>>&adj, int start , vector<bool> &vis){

    vis[start]=true;

    for(int &v:adj[start]){
        if(!vis[v]){
            dfs(adj,v,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n  = isConnected.size();

        unordered_map<int,vector<int>>adj;

        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,false);
        int count =0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                count++;
            } 
        }

        return count;
    }
};