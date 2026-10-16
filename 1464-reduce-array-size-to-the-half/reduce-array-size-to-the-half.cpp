class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n  = arr.size();
        unordered_map<int,int> mp;

        for(int i =0; i<n; i++){
            mp[arr[i]]++;
        }

        priority_queue<int>pq;

        for(auto it:mp){
            int freq = it.second;
            pq.push(freq);
        }


        int ans = 0;
        int removed = 0;

        while((removed*2)<n){
            
           int top = pq.top();
           pq.pop();
           cout<<ans<<" ";
           removed+=top;
           ans++;
        }
        return ans;
    }
};