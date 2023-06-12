//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod=1e9+7;
    vector<int> dp;
    long long solve(int pos,int n){
        if(pos>n){
            return 0;
        }
        if(pos==n){
            return 1;
        }
        if(dp[pos]!=-1){
            return dp[pos];
        }
        int ans=0;
        for(int jump=1;jump<=3;jump++){
            ans=ans%mod+solve(pos+jump,n)%mod;
            ans=ans%mod;
        }
        return dp[pos]=ans;
        
    }
    
    long long countWays(int n)
    {
        // your code here
        dp.resize(n+1,-1);
        return solve(0,n);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends