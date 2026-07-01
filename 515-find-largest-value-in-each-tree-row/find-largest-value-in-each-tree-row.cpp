/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;

        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            int maxVal = INT_MIN;

            while(size--){
                TreeNode* top = que.front();
                que.pop();

                if(top->val > maxVal){
                    maxVal = top->val;
                }

                if(top->left){
                    que.push(top->left);
                }
                if(top->right){
                    que.push(top->right);
                }
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};