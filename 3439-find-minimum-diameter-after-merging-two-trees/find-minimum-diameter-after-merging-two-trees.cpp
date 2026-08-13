class Solution {
public:

pair<int,int> BFS(unordered_map<int,vector<int>> &adj,int src){
    unordered_map<int,bool> vis;
    queue<int> que;

    int farthest_node = src;
    int distance = 0;

    vis[src] = true;
    que.push(src);

    while(!que.empty()){
        int size = que.size();

        for(int i= 0; i<size; i++){
           int curr_node = que.front();
           farthest_node = curr_node;
           que.pop();

           for(auto v: adj[curr_node]){
                if(vis[v]==false){
                    vis[v] = true;
                    que.push(v);
                }
           }
        }
        if(!que.empty()){
            distance++;
        }
    }
    return {farthest_node , distance};
}

int find_diameter(unordered_map<int,vector<int>> &adj){
    auto[farthest,distance] = BFS(adj,0);
    auto[otherend,diameter] = BFS(adj,farthest);

    return diameter;
}
  unordered_map<int,vector<int>>buildAdj(vector<vector<int>>&edges){
    unordered_map<int,vector<int>> adj;

    for(auto vec : edges){
        int u = vec[0];
        int v = vec[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
  }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int,vector<int>>adj2 = buildAdj(edges2);

        int d1 = find_diameter(adj1);
        int d2 = find_diameter(adj2);
        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1,d2,combined});
    }
};