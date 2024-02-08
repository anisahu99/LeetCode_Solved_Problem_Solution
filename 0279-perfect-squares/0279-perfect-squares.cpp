class Solution {
public:
    int solve(int n,vector<int> &dp){
	    if(n<0) return INT_MAX;
	    if(dp[n]!=-1) return dp[n];
	    int sq=sqrt(n);
	    if(n-(sq*sq)==0) return 1;
	    int ans=INT_MAX;
	    for(int i=sq;i>=1;i--){
	        ans=min(ans,solve(n-(i*i),dp));
	    }
	    return dp[n]=1+ans;
	}
	
	int solveTab(int n){
	    vector<int> dp(n+1,0);
	    
	    for(int num=1;num<=n;num++){
	        int sq=sqrt(num);
	        int ans=INT_MAX;
	        for(int i=sq;i>=1;i--){
	            ans=min(ans,dp[num-(i*i)]);
	        }
	        dp[num]=1+ans;
	    }
	    return dp[n];
	}
    
    int numSquares(int n) {
        // vector<int> dp(n+1,-1);
	   // return solve(n,dp);
	   
	   return solveTab(n);
    }
};