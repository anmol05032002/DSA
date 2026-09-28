class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;

        int maxi = -1;
        int count = 0;
        
        for(char i:s){
            if(i=='('){
               count++; 
            }
            if(i==')'){
                count--;
            }
            maxi = max(count,maxi);
        }
        return maxi;
    }
};