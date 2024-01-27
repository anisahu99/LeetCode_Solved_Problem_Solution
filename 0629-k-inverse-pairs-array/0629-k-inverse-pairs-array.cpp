class Solution {
    vector<vector<int>> dp;
    int maxi=1e9+7;
    int fn(int i,int k)
    {
          if(i>=dp.size())
          return 0;
          if(dp[i][k]!=-1)
          return dp[i][k];
          int ans=0;
           // ans=(ans+fn(i+1,k))%maxi;
          for(int j=0;i+j<dp.size()&&k-j>=0;j++)
          {
                ans=(ans+fn(i+1,k-j))%maxi;
                
          }
        
          return dp[i][k]=ans;

    }
public:
    int kInversePairs(int n, int k) {
        dp.assign(n,vector<int>(k+1,-1));
        if(k==0)
        return 1;
        for(int i=0;i<n;i++)
        dp[i][0]=1;
        int ans=0;
        // for(int i=0;i<n;i++)
        ans=(ans+fn(0,k))%maxi;
        return ans;
        
    }
};