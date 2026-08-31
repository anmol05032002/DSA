class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)return false;
        
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        int j = 0;
        int i = 0;

        for(int i=0; i<n; i++){
            mp[hand[i]]++;
        }
        // int cnt = 1;

        // while(i<j){
        //     int x = hand[j];
        //     if(mp.find(x+1)!=mp.end()){
        //         j++;
        //         cnt++;
        //         mp[x]--;
        //         mp[x+1]--;
        //         if(cnt==groupSize){
        //             cnt = 1;

        //         }
        //     }
        //     else{
        //         return false;
        //     }
        // }

        // for(auto it:mp){
        //     int curr = it.first;
        // }

        for(int i =0; i<n; i++){
            int x = hand[i];

            if(mp[x]==0)continue;
            for(int j =0; j<groupSize; j++){
                if(mp[x+j]==0){
                    return false;
                }
                mp[x+j]--;
            }
        }
     return true;
    }
};