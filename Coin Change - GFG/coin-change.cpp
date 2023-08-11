//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
      long long int solveTab(int coins[],int N,int sum)
    {
        vector<vector<long long int>> dp(N+1,vector<long long int>(sum+1,0));
        for(int i=0;i<=N;i++)
        {
            dp[i][0]=1;
        }
        for(int i=N-1;i>=0;i--)
        {
            for(int j=1;j<=sum;j++)
            {
              long long  int take=0,notake=0;
                if(j>=coins[i])
                {
                    take=(long long)dp[i][j-coins[i]];
                }
                notake=dp[i+1][j];
                dp[i][j]=(long long)(take+notake);
              //  cout<<dp[i][j]<<endl;
            }
        }
        return(dp[0][sum]);
    }
    long long int count(int coins[], int N, int sum) {

        // code here.
        return solveTab(coins,N,sum);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends