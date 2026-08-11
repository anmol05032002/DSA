class Solution {
public:


 void dfs(unordered_map<int,vector<int>>&adj,vector<bool> &vis, int src){
    vis[src]= true;

    for(int &v: adj[src]){
        if(!vis[v]){
            dfs(adj,vis,v);
        }
    }
 }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        unordered_map<int,vector<int>>adj;
        for(int i=0; i<n; i++){
            for(int j = 0; j<rooms[i].size(); j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
  
        vector<bool> vis(n,false);
          dfs(adj,vis,0);

         for(int i=0; i<n; i++){
          if(vis[i]==false){
            return false;
           }
        }
         return true;
    }
};