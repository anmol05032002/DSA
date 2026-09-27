class Solution {
public:
    typedef pair<int,int>p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i =0; i<n; i++){
            mp[nums[i]]++;
        }

        priority_queue<p,vector<p>,greater<p>>pq;

        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            p temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }
        return ans;
    }
};