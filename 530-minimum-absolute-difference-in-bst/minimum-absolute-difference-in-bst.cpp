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
//   void inorder(TreeNode* root, vector<int> &temp){
//     if(root==NULL)return;
    
//     inorder(root->left,temp);
//     temp.push_back(root->val);
//     inorder(root->right,temp);
//   }
int diff_ans = INT_MAX;
TreeNode* prev = NULL;
void inorder(TreeNode* root){
    if(root==NULL)return;

    inorder(root->left);
    if(prev!=NULL){
        diff_ans = min(diff_ans,abs(prev->val - root->val));  
    }
    prev = root;
    inorder(root->right);
}
    int getMinimumDifference(TreeNode* root) {
    //    vector<int> temp;
    //    inorder(root,temp);

    //    int n = temp.size();

    //    int diff = INT_MAX;

    //    for(int i =0; i<n-1; i++){
    //     int x = abs(temp[i]-temp[i+1]);
    //     diff = min(diff,x);
    //    }
    //    return diff;

    inorder(root);
    return diff_ans;
    }
};