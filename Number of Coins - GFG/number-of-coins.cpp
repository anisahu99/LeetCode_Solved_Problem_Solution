//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	vector<vector<int>> dp;
	int solve(int i,int target,int &M,int &V,int coins[]){
	    
	    if(i==M){
	        if(target==V){
	            return 0;
	        }
	        else{
	            return INT_MAX-1;
	        }
	    }
	    if(dp[i][target]!=-1){
	        return dp[i][target];
	    }
	    
	    int take=INT_MAX;
	    if(target+coins[i]<=V){
	        
	        take=min(take,1+solve(i,target+coins[i],M,V,coins));
	    }
	    int not_take=INT_MAX;
	    not_take=0+min(not_take,solve(i+1,target,M,V,coins));
	    
	    return dp[i][target]=min(take,not_take);
	    
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    dp.resize(M,vector<int>(V+1,-1));
	    int ans=solve(0,0,M,V,coins);
	    return ans==INT_MAX-1?-1:ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends