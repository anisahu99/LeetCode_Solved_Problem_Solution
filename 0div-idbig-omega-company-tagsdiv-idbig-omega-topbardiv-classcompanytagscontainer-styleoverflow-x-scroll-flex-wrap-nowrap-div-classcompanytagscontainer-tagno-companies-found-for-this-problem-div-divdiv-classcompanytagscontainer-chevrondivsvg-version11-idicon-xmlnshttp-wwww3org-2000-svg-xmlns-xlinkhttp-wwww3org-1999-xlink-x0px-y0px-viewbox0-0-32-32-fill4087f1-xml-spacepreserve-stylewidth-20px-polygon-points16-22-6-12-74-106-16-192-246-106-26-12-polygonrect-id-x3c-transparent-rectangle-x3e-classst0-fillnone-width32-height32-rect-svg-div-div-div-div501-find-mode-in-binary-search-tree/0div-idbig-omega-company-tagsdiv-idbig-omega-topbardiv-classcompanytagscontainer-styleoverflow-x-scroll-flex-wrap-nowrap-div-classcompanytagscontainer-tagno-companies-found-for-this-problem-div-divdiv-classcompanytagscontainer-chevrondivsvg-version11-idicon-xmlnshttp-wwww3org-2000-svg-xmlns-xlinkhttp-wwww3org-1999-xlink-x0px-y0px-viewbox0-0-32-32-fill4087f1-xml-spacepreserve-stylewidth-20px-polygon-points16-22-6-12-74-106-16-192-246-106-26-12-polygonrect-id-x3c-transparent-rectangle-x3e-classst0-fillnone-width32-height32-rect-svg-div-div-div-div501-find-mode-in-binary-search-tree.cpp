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
    vector<int> modes;                       //vector to store result
int curr=INT_MIN;                         //variable to store current root value
int count=0;                              //variable to store count of current root 
int max_count=0;                          //variable to store max count till 

vector<int> findMode(TreeNode* root) {
   if(root==NULL)                              //base case for inorder traversal
    return modes;
    
    findMode(root->left);
    helper(root->val);                        //main work in inorder part
    findMode(root->right);
    
    return modes;
}

//helper function
void helper(int val){
    if(val!=curr){                                                     
	//this represent the node is visited first time, hence set the current value of node to this value              and set the count to 1
       curr=val;
       count=1;
    }
    
    else
	//this represent the node is visited previously hence count is increased
        count++;
    
    if(max_count<count){
	//this node has maximum count hence we should delete the previous vector. So we are setting the value of vector to this value and max_count as this count.
         modes = {val};
        max_count = count;
    }
        
    else if(max_count==count)
	//this node has count equal to mode value so we should add this node value in vector.
        modes.push_back(val);
    
}
};