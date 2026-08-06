class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>>adj;
         vector<int> indegree(n,0);

        for(auto &vec: invocations){
            int u  = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
         
        
         vector<bool> suspicious(n,false);

         queue<int> que;
         que.push(k);
         suspicious[k] = true;

         while(!que.empty()){
            int top = que.front();
            que.pop();

            for(int & nbr: adj[top]){
                indegree[nbr]--;
                if(!suspicious[nbr]){
                    suspicious[nbr] = true;
                    que.push(nbr);
                }
            }
         }

         vector<int> result;
        bool cannotRemove = false;
        
        for(int i = 0; i < n; i++) {
            if(suspicious[i] && indegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if(!suspicious[i]) {
                result.push_back(i);
            }

        }

      if(cannotRemove){
        vector<int> ans(n);
        for(int i =0; i<n; i++){
               ans[i] = i;
        }
        return ans;
      }
      return result;
    }
};