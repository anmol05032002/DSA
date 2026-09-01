class Solution {
public:

    int digitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int countBalls(int lowLimit, int highLimit) {
        vector<int> mp(50, 0);

        int maxi = 0;

        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = digitSum(i);
            mp[sum]++;
            maxi = max(maxi, mp[sum]);
        }

        return maxi;
    }
};