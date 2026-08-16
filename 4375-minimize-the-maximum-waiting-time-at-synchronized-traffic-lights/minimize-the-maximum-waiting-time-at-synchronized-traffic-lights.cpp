class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxm = -1;
        int ans = 0;

        int n = lights.size();
        int m = arrivalTime.size();

        for(int i=0; i<n; i++){
            maxm = max(maxm,lights[i]);
        }

        for(int i =0; i<m; i++){
            int r = arrivalTime[i]%period;

            if(r<maxm){
                continue;
            }
            else{
                ans = max(ans,period-r);
            }
        }
        return ans;
    }
};