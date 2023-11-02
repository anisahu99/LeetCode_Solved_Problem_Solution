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
    int count=0;
    pair<int,int> SumAndTotalNodes(TreeNode* root){
        
        if(!root) return {0,0};
        
        pair<int,int> leftS=SumAndTotalNodes(root->left);
        pair<int,int> rightS=SumAndTotalNodes(root->right);
        
        int avg=(leftS.first+rightS.first+root->val)/(leftS.second+rightS.second+1);
        if(avg==root->val) count++;
        pair<int,int> giveToParent={leftS.first+rightS.first+root->val,leftS.second+rightS.second+1};
        return giveToParent;
    }
    int averageOfSubtree(TreeNode* root) {
        SumAndTotalNodes(root);
        return count;
    }
};