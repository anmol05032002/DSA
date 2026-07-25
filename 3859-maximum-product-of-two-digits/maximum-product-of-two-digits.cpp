class Solution {
public:
    int maxProduct(int n) {
        int maxi =0;
        vector<int>prod;
        while(n!=0){
            int d = n%10;
            prod.push_back(d);
            n/=10;
        }

        sort(prod.begin(),prod.end());

        int size = prod.size();

        return prod[size-1]*prod[size-2];
    }
};