class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int j = 1;
        int ans = 0;

        while (i < n) {

            if (j < n && chars[i] == chars[j]) {
                j++;
            }
            else {
                chars[ans++] = chars[i];

                if (j - i > 1) {
                    string s = to_string(j - i);

                    for (char c : s)
                        chars[ans++] = c;
                }

                i = j;
                j++;
            }
        }

        return ans;
    }
};