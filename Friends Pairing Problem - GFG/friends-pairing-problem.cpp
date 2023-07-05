//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n==0||n==1||n==2){
            return n;
        }
        int mod=1e9+7;
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <=n; i++)
        {
            dp[i] = (dp[i-1]%mod + 1LL*(i-1)*(dp[i-2]%mod))%mod;
            
        }
        return dp[n];
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends