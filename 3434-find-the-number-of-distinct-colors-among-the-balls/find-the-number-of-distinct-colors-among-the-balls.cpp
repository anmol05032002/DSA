class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();
        // set<int>s;
        // vector<int> mp(limit+1,0);

        // for(int i =0; i<n; i++){
        //     int x = queries[i][0];
        //     int y = queries[i][1];
        //     mp[x] = y;
        //     for(auto it: mp){
        //         if(it>0){
        //            s.insert(it);
        //         }
        //     }
        //     int sz = s.size();
        //     ans.push_back(sz);
        //     s.clear();
        // }

        unordered_map<int,int>ballmp;
        unordered_map<int,int>colorCount;

        for(int i=0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballmp.find(ball)==ballmp.end()){
                ballmp[ball] = color;
                colorCount[color]++;
            }
            else{
                int prevColor = ballmp[ball];
                ballmp[ball] = color;
                colorCount[prevColor]--;
                if(colorCount[prevColor]==0){
                    colorCount.erase(prevColor);
                }
                colorCount[color]++;
            }
            int size = colorCount.size();
            ans.push_back(size);
        }
        return ans;
    }
};