class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;

        string s = to_string(n);
        string st = "";

        for (char c : s) {
            int digit = c - '0';
            sum += digit;

            if (c != '0')
                st += c;
        }

        long long num = st.empty() ? 0 : stoll(st);

        return sum * num;
    }
};