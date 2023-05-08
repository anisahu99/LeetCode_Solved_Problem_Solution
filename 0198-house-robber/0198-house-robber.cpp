class Solution {
public:
    int dp[101];
    int solve(int i,vector<int>& nums){
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1){
            //cout<<dp[i]<<endl;
            return dp[i];
        }
        int take=nums[i]+solve(i+2,nums);
        int not_take=0+solve(i+1,nums);
        
        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};