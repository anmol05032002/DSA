class Solution {
public:
    int maxDistance(string moves) {
        int n = moves.length();
        int x  =0;
        int y =0;
        int cnt=0;

        for(int i=0; i<n; i++){
            if(moves[i]=='U'){
                y++;
            }
            if(moves[i]=='D'){
                y--;
            }
            if(moves[i]=='L'){
                x--;
            }
            if(moves[i]=='R'){
                x++;
            }
            if(moves[i]=='_')cnt++;
        }
        return abs(x) + abs(y) + cnt;
    }
};