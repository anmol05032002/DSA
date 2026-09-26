class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int n = piles.size();
        priority_queue<int>pq;

        for(auto it: piles){
            pq.push(it);
        }

        while(k!=0){
            int top = pq.top();
            pq.push((top+1)/2);
            pq.pop();
            k--;
        }

        int ans = 0;

        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            ans+=temp;
        }
        return ans;
    }
};