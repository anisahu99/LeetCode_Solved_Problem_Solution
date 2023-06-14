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
    vector<int> inorder;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        inorder.push_back(root->val);
        solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        int ans=INT_MAX;
        for(int i=0;i<inorder.size()-1;i++){
            ans=min(ans,inorder[i+1]-inorder[i]);
        }
        return ans;
    }
};