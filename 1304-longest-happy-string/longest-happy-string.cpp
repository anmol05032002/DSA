class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        string ans;
        while (!pq.empty()) {
            auto [n1, c1] = pq.top(); pq.pop();
            int len = ans.size();

            if (len >= 2 && ans[len-1] == c1 && ans[len-2] == c1) {
                if (pq.empty()) break;        
                auto [n2, c2] = pq.top(); pq.pop();
                ans += c2;
                if (--n2) pq.push({n2, c2});
                pq.push({n1, c1});             
            } else {
                ans += c1;
                if (--n1) pq.push({n1, c1});
            }
        }
        return ans;
    }
};