class Solution {
public:
    typedef pair<char,int> p;
    struct lamda {
        bool operator()(p &p1 ,p &p2){
            return p1.second < p2.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<p,vector<p>,lamda> pq;
        unordered_map<char,int>mp;

        for(auto it: s){
            mp[it]++;
        }

        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        string ans = "";
        while(!pq.empty()){
            p temp= pq.top();
            pq.pop();
            ans+=string(temp.second,temp.first);
        }
        return ans;
    }
};