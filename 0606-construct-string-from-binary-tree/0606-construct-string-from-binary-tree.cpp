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
    string help(TreeNode* root){
        if(!root) return "";
        
        string l=help(root->left);
        string r=help(root->right);
        
        string res=to_string(root->val);
        
        //cout<<res<<", "<<l<<", "<<r<<endl;
        
        if(l!=""||r!=""){
            res=res+"("+l+")";
        }
        if(r!=""){
            res=res+"("+r+")";
        }
        //cout<< res<<endl;
        return res;
    }
    string tree2str(TreeNode* root) {
        return help(root);
    }
};