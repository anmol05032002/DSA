class Solution {
public:
    bool checkDivisibility(int n) {
        int a =n;
        int dig_sum = 0;
        int dig_mul = 1;

        while(a!=0){
            int d = a%10;
            dig_sum+=d;
            dig_mul*=d;
            a/=10;
        }
        // cout<< dig_sum<<endl;
        // cout<<dig_mul<<endl;

        return (n %(dig_sum+dig_mul)==0);
    }
};