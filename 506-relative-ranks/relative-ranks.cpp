class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<int> pq;
         int count  = 0;
        for(int &num: score){
            pq.push(num);

        }
        unordered_map<int,string> mp;
        while(!pq.empty()){
            // cout<<pq.top()<<" ";
            // pq.pop();
            int top = pq.top();
            pq.pop();
            count++;
            if(count==1){
                mp[top] = "Gold Medal";
            }
            else if(count==2){
                mp[top] = "Silver Medal";
            }
           else if(count==3){
                mp[top] = "Bronze Medal";
            }
            else{
                mp[top] = to_string(count);
            }
        }

        vector<string> ans;

        for(int i =0; i<n; i++){
            string s = mp[score[i]];
            ans.push_back(s);
        }
       return ans;
    }
};