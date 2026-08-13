class Solution {
public:
    stack<int> s;

    void dfs(unordered_map<int, vector<int>>& adj, int start) {

        while (!adj[start].empty()) {

            int v = adj[start].back();

            adj[start].pop_back();

            dfs(adj, v);
        }

        s.push(start);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int>> ans;
        int n = pairs.size();

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> inDegree, outDegree;

        for (auto vec : pairs) {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);

            inDegree[v]++;
            outDegree[u]++;
        }

        int startnode = pairs[0][0];

        for (auto it : adj) {
            int u = it.first;

            if (outDegree[u] - inDegree[u] == 1) {
                startnode = u;
                break;
            }
        }

        vector<int> path;

        dfs(adj, startnode);

        while (!s.empty()) {
            int top = s.top();
            s.pop();
            path.push_back(top);
        }

        // reverse(path.begin(), path.end());
        // for(int i =0; i<path.size()-1; i++){
        //     cout<<path[i]<<" ";
        // }

        for (int i = 0; i < path.size() - 1; i++) {
            ans.push_back({path[i], path[i + 1]});
        }

        return ans;
    }
};