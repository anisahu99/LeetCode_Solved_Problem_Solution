//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int mod=1e9+7;
    int solveTab(int n){
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int one=0,two=0;
            if(i-1>=0){
                one=dp[i-1]%mod;
            }
            if(i-2>=0){
                two=dp[i-2]%mod;
            }
            dp[i]=(one+two)%mod;
        }
        return dp[n];
    }
    int countWays(int n)
    {
        // your code here
        
        return solveTab(n);
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