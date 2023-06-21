//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
  long long int func(int ind,int coins[],int sum,vector<vector<int long long >>&dp){
      if(sum==0){
          return 1;
      }
      if(ind==-1){
          return 0;
      }
    //   if(ind==0){
    //       if(sum%coins[0]==0) return 1;
    //       else return 0;
    //   }
      if(dp[ind][sum]!=-1) return dp[ind][sum];
      int long long dont=func(ind-1,coins,sum,dp);
      int long long take=0;
      if(coins[ind]<=sum){
          take=func(ind,coins,sum-coins[ind],dp);
      }
      
      return dp[ind][sum]= dont+take;
  }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<int long long>> dp(N,vector<int long long>(sum+1,-1));
        return func(N-1,coins,sum,dp);
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