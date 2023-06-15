//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod=1e9+7;
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<long long int>> dp(m,vector<long long int>(n,0));
        for(int row=m-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                if(row==m-1||col==n-1){
                    dp[row][col]=1;
                }
                else{
                    dp[row][col]=(dp[row+1][col]%mod+dp[row][col+1]%mod)%mod;
                }
            }
        }
        return dp[0][0]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends