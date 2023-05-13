class Solution {
public:
    
    //we have two options either we take 0 Zero time or 1 One times
    vector<int> dp;
    int mod=1e9+7;
    int solve(int l,int &zero,int &one,int &low,int &high){
        if(l>high)
            return 0;
        
        if(high==l){
            return 1;
        }
        if(dp[l]!=-1){
            //cout<<dp[l]<<endl;
            return dp[l]%mod;
        }
        
        int c1=solve(l+zero,zero,one,low,high)%mod;
        int c2=solve(l+one,zero,one,low,high)%mod;
        if(l>=low){
            return dp[l]=(1+c1+c2)%mod;
        }
        return dp[l]=(c1+c2)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high,-1);
        return solve(0,zero,one,low,high);
    }
};