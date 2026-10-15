class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;

        for(int &num:amount){
            if(num!=0)
            pq.push(num);
        }
        int ans = 0;
        if(pq.size()==0)return 0;

        while(!pq.empty() && pq.size()>1){
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            if(a>0){
                a--;
                if(a!=0){
                    pq.push(a);      
                }
            }
            if(b>0){
                b--;
                if(b!=0){
                    pq.push(b);  
                }
            }
            ans++;
        }
        if(pq.size()==0)return ans;
        return ans + pq.top();
    }
};