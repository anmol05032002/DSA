class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int ans = 0;

        for(int i = 0; i<n; i++){
            for(int j =i+1; j<n; j++){
                int first_x = intervals[i][0];
                int second_x = intervals[j][0];
                int first_y = intervals[i][1];
                int second_y = intervals[j][1];

                if(max(first_x,second_x)<=min(first_y,second_y)){
                    ans++;
                }
            }
        }
        return ans;
    }
};