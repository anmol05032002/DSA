class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i =0;
        long long j = sqrt(c);

        while(i<=j){
            long long curr_sum = i*i + j*j;

            if(curr_sum==c){
                return true;
            }
            else if(curr_sum<c){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};