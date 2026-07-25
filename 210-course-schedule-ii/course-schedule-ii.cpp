class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;

        unordered_map<int,vector<int>>adj;

        for(int i=0; i<prerequisites.size(); i++){
            int u  = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int>indegree(numCourses,0);

        for(int u =0; u<numCourses; u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }

        queue<int>q;
        for(int i =0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){

            int u = q.front();
            ans.push_back(u);
            q.pop();

            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        if(ans.size()==numCourses){
             return ans;
        }
       return {};
    }
};