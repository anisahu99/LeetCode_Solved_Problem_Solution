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
 void dfs(TreeNode* root,int level){
        if(!root) return;
        mp[level]=mp[level]+root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        
        int level=1;
        int sum=root->val;
        dfs(root,1);
        for(auto it:mp){
            if(it.second>sum){
                level=it.first;
                sum=it.second;
            }
            else if(it.second==sum){
                if(level>it.first){
                    level=it.first;
                }
            }
        }
        return level;
    }
};