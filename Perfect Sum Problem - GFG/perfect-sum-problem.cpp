//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int solve(int i,int target,int &n,int &sum,int arr[],vector<vector<int>> &dp){
	    if(i==n){
	        if(target==sum) return 1;
	        else return 0;
	    }
	    if(dp[i][target]!=-1) return dp[i][target];
	    int cnt=0;
	    if(arr[i]+target<=sum){
	        cnt=(cnt%mod+solve(i+1,arr[i]+target,n,sum,arr,dp)%mod)%mod;
	    }
	    
	    int not_take=solve(i+1,target,n,sum,arr,dp)%mod;
	    
	    return dp[i][target]=(cnt+not_take)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,0,n,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends