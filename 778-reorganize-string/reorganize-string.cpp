class Solution {
public:
    string reorganizeString(string s) {

        int n = s.length();
        vector<int> count(26, 0);

        for(char c : s) {
            count[c - 'a']++;
        }

        priority_queue<pair<int,char>> pq;

        for(char c = 'a'; c <= 'z'; c++) {
            if(count[c - 'a'] > 0) {
                pq.push({count[c - 'a'], c});
            }
        }

        string ans = "";

        while(pq.size() >= 2) {

            auto p1 = pq.top();
            pq.pop();

            auto p2 = pq.top();
            pq.pop();

            ans += p1.second;
            ans += p2.second;

            p1.first--;
            p2.first--;

            if(p1.first > 0)
                pq.push(p1);

            if(p2.first > 0)
                pq.push(p2);
        }

        if(!pq.empty()) {

            auto p = pq.top();

            if(p.first > 1)
                return "";

            if(!ans.empty() && ans.back() == p.second)
                return "";

            ans += p.second;
        }

        return ans;
    }
};