class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n  = isConnected.size();

        unordered_map<int,vector<int>>adj;
        vector<bool>vis(n,false);

        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
         int count =0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i]=true;
                count++;
                queue<int>que;
                que.push(i);

                while(!que.empty()){
                    int front = que.front();
                    que.pop();

                    for(int &v:adj[front]){
                        if(!vis[v]){
                            que.push(v);
                            vis[v]=true;
                        }
                    }
                }
            }
        }
        return count;
    }
};