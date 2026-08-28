class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        map<vector<int>,int> mp;
        
        for(int r = 0; r<n; r++){
            mp[grid[r]]++;
        }

        for(int c = 0; c<n; c++){
            vector<int> v;
            for(int r = 0; r<n; r++){
                v.push_back(grid[r][c]);
            }
            ans+=mp[v];
        }
        return ans;
    }
};