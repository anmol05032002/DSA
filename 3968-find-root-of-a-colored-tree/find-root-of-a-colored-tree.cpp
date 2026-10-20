class Solution {
public:

    bool bfs(vector<vector<int>>& adj, int root, int color, string& colors, unordered_map<char, int>& mp) {

        int n = adj.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(root);
        vis[root] = true;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int top = q.front();
                q.pop();

                if (mp[colors[top]] != color) return false;  

                int children = 0;
                for (int &v : adj[top]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                        children++;
                    }
                }
                if (children > 2) return false;               
            }

            color = (color + 1) % 3;
        }
        return true;
    }

    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<char, int> mp;
        mp['R'] = 0;
        mp['B'] = 1;
        mp['W'] = 2;

    
        int root = -1;
        for (int i = 0; i < n; i++) {
            int prev = (mp[colors[i]] + 2) % 3;
            bool hasParent = false;
            for (int &v : adj[i]) {
                if (mp[colors[v]] == prev) {
                     hasParent = true; break; 
                 }
            }
            if (!hasParent) {
                if (root != -1) return -1;    
                root = i;
            }
        }
        if (root == -1) return -1;

     
        if (bfs(adj, root, mp[colors[root]], colors, mp)) return root;
        return -1;
    }
};