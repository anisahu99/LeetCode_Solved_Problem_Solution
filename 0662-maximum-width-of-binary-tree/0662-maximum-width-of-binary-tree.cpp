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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll ans=0;
        while(!q.empty()){
            int sz=q.size();
            ll mn=q.front().second;
            ll mx=q.front().second;
            while(sz--){
                pair<TreeNode*,ll> p=q.front();q.pop();
                mn=min(mn,p.second);
                mx=max(mx,p.second);
                if(p.first->left){
                    q.push({p.first->left,(2*p.second)+1});
                }
                if(p.first->right){
                    q.push({p.first->right,(2*p.second)+2});
                }
            }
            ans=max(ans,(mx-mn+1));
        }
        return ans;
    }
};