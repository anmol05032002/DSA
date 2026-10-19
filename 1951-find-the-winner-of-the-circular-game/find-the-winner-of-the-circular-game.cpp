class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> store;

        for(int i =1; i<=n; i++){
            store.push_back(i);
        }

        int i =0;

        while(store.size()>1){
            int idx = (i+k-1)%store.size();
            store.erase(store.begin()+idx);
            i = idx;
        }

        return store[0];
    }
};