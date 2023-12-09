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
        private:
        void dfs(TreeNode* root,vector<int>&store){
                if(root==NULL)
                        return;
                dfs(root->left,store);
                store.push_back(root->val);
                dfs(root->right,store);
                
                return;
        }
public:
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int>store;
            dfs(root,store);
            return store;
        
    }
};