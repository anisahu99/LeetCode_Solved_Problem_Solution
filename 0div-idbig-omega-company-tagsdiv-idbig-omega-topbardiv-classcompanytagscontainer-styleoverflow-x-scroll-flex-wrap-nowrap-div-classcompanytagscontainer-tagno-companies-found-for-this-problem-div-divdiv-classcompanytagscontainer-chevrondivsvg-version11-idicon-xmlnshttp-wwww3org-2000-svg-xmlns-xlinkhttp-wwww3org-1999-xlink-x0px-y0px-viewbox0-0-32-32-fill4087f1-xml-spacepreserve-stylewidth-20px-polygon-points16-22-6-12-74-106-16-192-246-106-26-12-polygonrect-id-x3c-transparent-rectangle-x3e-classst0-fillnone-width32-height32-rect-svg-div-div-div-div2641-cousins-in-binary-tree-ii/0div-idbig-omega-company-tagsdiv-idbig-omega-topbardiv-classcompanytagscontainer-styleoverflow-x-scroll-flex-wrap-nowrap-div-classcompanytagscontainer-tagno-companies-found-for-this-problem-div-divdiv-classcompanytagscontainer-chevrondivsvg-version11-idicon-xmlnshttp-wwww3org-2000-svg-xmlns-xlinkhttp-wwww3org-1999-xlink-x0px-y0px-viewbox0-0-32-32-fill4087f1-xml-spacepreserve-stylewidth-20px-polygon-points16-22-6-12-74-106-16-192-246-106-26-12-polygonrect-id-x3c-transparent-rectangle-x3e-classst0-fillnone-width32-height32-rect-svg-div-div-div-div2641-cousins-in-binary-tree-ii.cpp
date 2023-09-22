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
//     unordered_map<TreeNode*,TreeNode*> parent;
//     void make_parent(TreeNode* root){
//         if(!root) return;
//         if(root->left){
//             parent[root->left]=root;
//             make_parent(root->left);
//         }
//         if(root->right){
//             parent[root->right]=root;
//             make_parent(root->right);
//         }
        
//     }
    
    void find_level_sum(unordered_map<int,int> &sum,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            int s=0;
            for(int i=0;i<sz;i++){
                TreeNode* temp=q.front();q.pop();
                s+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            sum[level]=s;
            level++;
        }
    }
    
    void PostOrder(TreeNode* root,int depth,unordered_map<int,int> &sum){
        if(!root) return;
        if(root->left||root->right){
            int v=0;
            if(sum.find(depth+1)!=sum.end()) v=sum[depth+1];
            v=v-(root->left?root->left->val:0)-(root->right?root->right->val:0);
            if(root->left){
                root->left->val=v;
            }
            if(root->right){
                root->right->val=v;
            }
        }
        PostOrder(root->left,depth+1,sum);
        PostOrder(root->right,depth+1,sum);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int,int> sum;
        find_level_sum(sum,root);
        PostOrder(root,0,sum);
        if(root) root->val=0;
        
        return root;
    }
};