class Solution {
public:
    int countCommas(int n) {
        // return 3;
        int x = n;

        // int count_digt = 0;
        // while(x!=0){
        //     x/=10;
        //     count_digt++;
        // }

        // if(count_digt>3)return count_digt/4 + n-1000;

        if(n>999)return n-999;
        return 0;
    }
};