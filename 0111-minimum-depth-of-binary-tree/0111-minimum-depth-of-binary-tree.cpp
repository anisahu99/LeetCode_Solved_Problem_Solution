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
    int solve(TreeNode* root){
        if(!root) return (0);
        
        
        int left=solve(root->left);
        int right=solve(root->right);
        if(left==0&&right){
            return (1+right);
        }
        if(right==0&&left){
            return (1+left);
        }
        
        return min(1+left,1+right);
    }
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};