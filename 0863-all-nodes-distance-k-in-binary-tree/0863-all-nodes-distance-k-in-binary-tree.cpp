/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void print(unordered_map<TreeNode*,TreeNode*>& mp){
        for(auto it:mp){
            cout<<it.first->val<<":"<<it.second->val<<endl;
        }
    }
    void make_links(TreeNode*root,unordered_map<TreeNode*,TreeNode*>& mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();q.pop();
            if(temp->left){
                q.push(temp->left);
                mp[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                mp[temp->right]=temp;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        make_links(root,mp);
        queue<TreeNode*> q;
        int level=0;
        q.push(target);
        vector<int> ans;
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        while(!q.empty()){
            
            if(level==k){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
            }
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* temp=q.front();q.pop();
                if(temp->left&&vis.find(temp->left)==vis.end()){
                    q.push(temp->left);
                    vis.insert(temp->left);
                }
                if(temp->right&&vis.find(temp->right)==vis.end()){
                    q.push(temp->right);
                    vis.insert(temp->right);
                }
                if(mp.find(temp)!=mp.end()&&vis.find(mp[temp])==vis.end()){
                    q.push(mp[temp]);
                    vis.insert(mp[temp]);
                }
            }
            level++;
        }
        return ans;
    }
};