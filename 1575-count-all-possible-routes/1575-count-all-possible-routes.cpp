class Solution {
public:
    int n;
    int mod=1e9+7;
    int dp[101][201];
    int solve(vector<int>& locations, int start, int finish, int fuel){
        if(fuel<0)
            return 0;
        if(dp[start][fuel]!=-1){
            return dp[start][fuel];
        }
        if(start==finish){
            int ans=1;
            for(int i=0;i<n;i++){
                if(i==start) continue;
                ans=(ans%mod+solve(locations,i,finish,fuel-abs(locations[start]-locations[i]))%mod)%mod;
            }
            return dp[start][fuel]=ans%mod;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==start) continue;
            ans=(ans%mod+solve(locations,i,finish,fuel-abs(locations[start]-locations[i]))%mod)%mod;
        }
        return dp[start][fuel]=ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n=locations.size();
        memset(dp,-1,sizeof(dp));
        return solve(locations,start,finish,fuel);
    }
};