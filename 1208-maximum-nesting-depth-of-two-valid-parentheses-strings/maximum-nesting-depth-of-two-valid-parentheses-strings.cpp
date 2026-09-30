class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int n = seq.length();

        vector<char> str;
        int depth = 0;

        for(int i =0; i<n; i++){
            if(seq[i]=='('){
                ans.push_back(depth%2);
                depth++;
                
            }
            else{
                depth--;
                ans.push_back(depth%2);
                
            }
        }
        return ans;
    }
};