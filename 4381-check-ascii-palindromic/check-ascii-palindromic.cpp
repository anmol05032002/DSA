class Solution {
public:

    string binary(int n) {
        string result;
        for (int i = 0; i < 8; i++) {
            result.push_back((n % 2) + '0');
            n /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool isPalindromic(string s) {
        string bin = "";
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int a = (int)s[i];  
            string str = binary(a);
            bin += str;
        }

        int m = bin.length();
        int i = 0, j = m - 1;

        while (i < j) {
            if (bin[i] != bin[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};