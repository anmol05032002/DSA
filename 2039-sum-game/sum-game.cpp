class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int mid = n / 2;

        int first_half = 0;
        int second_half = 0;

        int q1 = 0;
        int q2 = 0;

        for (int i = 0; i < mid; i++) {
            if (num[i] == '?')
                q1++;
            else
                first_half += num[i] - '0';
        }

        for (int i = mid; i < n; i++) {
            if (num[i] == '?')
                q2++;
            else
                second_half += num[i] - '0';
        }

        if ((q1 + q2) % 2 == 1)
            return true;

        int diff = first_half - second_half;
        int effect = (q1 - q2) / 2 * 9;
        if (diff + effect == 0)
            return false;

        return true;
    }
};