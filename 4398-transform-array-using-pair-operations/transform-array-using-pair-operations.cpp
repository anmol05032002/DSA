class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        // return true;

        int n  = source.size();
        long long sum = 0;

        for(int i =0; i<n; i++){
            if(source[i]!=target[i]){
                sum+= (long long)(target[i] - source[i]);
            }
        }

        return sum==0;

    }
};