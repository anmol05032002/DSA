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
    int currnum = 0;
    int curfreq = 0;
    int maxfreq = 0;
    vector<int> result;

    void dfs(TreeNode* root){
        if(root==NULL)return;

        dfs(root->left);

        if(currnum==root->val){
            curfreq++;
        }else{
            currnum = root->val;
            curfreq =1;
        }

        if(curfreq > maxfreq){
            result = {};
            maxfreq = curfreq;
        }
        if(curfreq == maxfreq){
            result.push_back(currnum);
        }

        dfs(root->right);
    }


    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return result;
    }
};