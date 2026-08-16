class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini = INT_MAX;
        int idx = -1;

        int n = drones.size();

        for(int i =0; i<n; i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];

            int dist = abs(target[0]-x) + abs(target[1]-y);

            if(dist<=range && dist<mini){
                mini = dist;
                idx = i;
            }
        }
        return idx;
    }
};