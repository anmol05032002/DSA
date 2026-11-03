class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;

        for(int i =0; i<n; i++){
            maxi = max(maxi,nums[i]);
        }

        int moves = 0;

        for(int i =0; i<n; i++){
            if((maxi-nums[i])>=0){
                moves+=(maxi-nums[i]);
            }
        }

        return moves;
    }
};