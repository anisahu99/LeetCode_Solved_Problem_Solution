class Solution {
public:
    void dfs(vector<int> &nums,vector<int> res,vector<vector<int>>& ans){
        if(res.size()==nums.size()){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            nums[i]=-20;
            if(num!=-20){
                res.push_back(num);
                dfs(nums,res,ans);
                res.pop_back();
            }
            nums[i]=num;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(nums,res,ans);
        return ans;
    }
};