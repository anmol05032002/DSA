class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int,int>lost_map;
        int n = matches.size();

        for(int i = 0; i<n; i++){
            lost_map[matches[i][1]]++;
        }

        vector<int>not_lost;
        vector<int>one_lost;

        for(int i =0; i<n; i++){
            int win = matches[i][0];
            int lost = matches[i][1];
            if(lost_map[lost]==1){
                one_lost.push_back(lost);
            }
            if(lost_map.find(win)==lost_map.end()){
                not_lost.push_back(win);
                lost_map[win]=2;
            }
        }
        sort(not_lost.begin(),not_lost.end());
        sort(one_lost.begin(),one_lost.end());
        ans.push_back(not_lost);
        ans.push_back(one_lost);
        return ans;
    }
};