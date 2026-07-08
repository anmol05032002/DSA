class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n  = tokens.size();

        stack<int>s;
        int i =0;
        int ans =0;

        while(i<n){
            if(tokens[i]=="+" ||  tokens[i]=="*" || tokens[i]=="-" || tokens[i]=="/" ){
               string op = tokens[i];
               int b = s.top();
               s.pop();
               int a = s.top();
               s.pop();

                 if (op == "+" )
                 ans = a + b;
                 else if (op == "-" )
                 ans = a - b;
                 else if (op == "*")
                 ans = a * b;
                 else if (op == "/" )
                  ans = a / b;

                  s.push(ans);

            }
            else
            s.push(stoi(tokens[i]));  // ✓ handles negatives like "-3" too
            i++;
        }

        int val = s.top();
        return val;
        
    }
};