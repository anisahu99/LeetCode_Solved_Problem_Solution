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
    TreeNode* help(TreeNode* root){
        TreeNode* temp=root;
        TreeNode* ans=temp;
        while(temp->right){
            ans=temp->right;
            temp=temp->right;
        }
        return ans;
    }
    TreeNode* solve(TreeNode* root){
        if(!root) return root;
        // if(!root->left&&!root->right) return root;
        // cout<<root->val<<" ";
        TreeNode* l=solve(root->left);
        TreeNode* r=solve(root->right);
        root->left=NULL;
        root->right=NULL;
        if(!l){
            root->right=r;
        }
        else{
            root->right=l;
            TreeNode* leaf=help(l);
            leaf->right=r;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};