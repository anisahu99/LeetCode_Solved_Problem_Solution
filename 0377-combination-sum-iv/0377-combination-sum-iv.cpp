class Solution {
public:
    int t[1001];
    int solve(int sum,int &target,int &n,vector<int> &nums){
        if(sum==target){
            return 1;
        }
        
        if(t[sum]!=-1) return t[sum];
        
        int take=0;
        for(int j=0;j<n;j++){
            if(sum+nums[j]<=target){
                take=take+solve(sum+nums[j],target,n,nums);
            } 
        }           
                
        return t[sum]=take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,target,n,nums);
    }
};