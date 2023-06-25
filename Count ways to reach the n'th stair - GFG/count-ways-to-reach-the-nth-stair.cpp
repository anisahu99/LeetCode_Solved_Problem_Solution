//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod=1e9+7;
    vector<int> dp;
    int solve(int n)
    {
        // your code here
        if(n==0){
            return 1;
        }
        if(n<1){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int one=solve(n-1)%mod;
        int two=solve(n-2)%mod;
        
        return dp[n]=(one+two)%mod;
    }
    int countWays(int n)
    {
        // your code here
        
        dp.resize(n+1,-1);
        return solve(n);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends