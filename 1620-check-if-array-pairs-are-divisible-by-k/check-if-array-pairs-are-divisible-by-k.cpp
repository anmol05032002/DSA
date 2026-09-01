class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        // sort(arr.begin(),arr.end());
        for(int i = 0; i<n; i++){
            arr[i] = ((arr[i]%k)+k)%k;
        }
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        if(mp.size()==1 && mp[0]==0)return false;
        if(mp.size()==1 && mp[0]!=0 && mp[0]%2==0)return true;
        for(int i = 1; i<=k/2; i++){
            if(mp[0]%2){
                return false;
            }
            if(i == k-i && mp[i]%2!=0)return false;
            if(mp[i]>0){
                if(mp.find(k-i)==mp.end() || mp[i]!=mp[k-i]){
                    return false;
                }
            }
        } 
        
        return true;
    }
};