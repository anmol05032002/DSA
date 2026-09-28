class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> vec(n); 
        for(int i = 0; i<n; i++) {
            vec[i] = {nums1[i], nums2[i]};
        }
        
        auto lambda = [&](auto &P1, auto &P2) {
            return P1.second > P2.second;
        };
        
        sort(begin(vec), end(vec), lambda);

        priority_queue<int,vector<int>,greater<int>> pq;

        long long Ksum = 0;
        for(int i = 0; i<k; i++){
            Ksum+=vec[i].first;
            pq.push(vec[i].first);
        }
        long long maxi = -1;
        long long result = Ksum*vec[k-1].second;
        maxi = max(maxi,result);

        for(int i = k; i<n; i++){
            int x = pq.top();
            if(x<vec[i].first){
                pq.pop();
                Ksum+=vec[i].first - x;
                result = Ksum*vec[i].second;
                pq.push(vec[i].first);
            }
            maxi = max(result,maxi);       
        }
    return maxi;
    }
};