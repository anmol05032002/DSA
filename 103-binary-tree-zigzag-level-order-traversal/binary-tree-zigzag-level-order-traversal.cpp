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

  void reverse(vector<int> &order){
    int n = order.size();
    int i =0;
    int j = n-1;

    while(i<j){
        swap(order[i],order[j]);
        i++;
        j--;
    }
  }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==NULL)return ans;

        queue<TreeNode*>que;
        que.push(root);
        int level =0;

        while(!que.empty()){
            int size = que.size();
            vector<int>order;

            while(size--){
                TreeNode* top = que.front();
                que.pop();
                
                 order.push_back(top->val);
                    if(top->left){
                        que.push(top->left);
                    }
                    if(top->right){
                        que.push(top->right);
                    }
                }
                if(level%2==0){
                    ans.push_back(order);
                }
                else{
                    reverse(order);
                    ans.push_back(order);
                }
                level++; 
        }
        return ans;
    }
};