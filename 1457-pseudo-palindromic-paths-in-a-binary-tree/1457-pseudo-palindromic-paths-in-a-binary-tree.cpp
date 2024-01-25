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
    unordered_map<int,int> mp;
    //string ans="";
    int count=0;
     void trv(TreeNode* root){
         if(!root) return;
         if(!root->left&&!root->right){
             mp[root->val]++;
             //ans+=to_string(root->val);
             if(isConsistPalindrome()) count++;
             //ans.pop_back();
             mp[root->val]--;
             return;
         }
         mp[root->val]++;
         //ans+=to_string(root->val);
         trv(root->left);
         trv(root->right);
         //ans.pop_back();
         mp[root->val]--;
     }
    bool isConsistPalindrome(){
        bool flag=true;
        for(auto it:mp){
            int freq=it.second;
            if(freq%2==1){
                if(flag) flag=false;
                else if(!flag) return false;
            }
        }
        return true;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        trv(root);
        return count;
    }
};