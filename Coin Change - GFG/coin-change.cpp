//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  vector<vector<long long int>> dp;
  long long int solve(int i,int currSum,int coins[],int sum,int N){
      if(currSum==sum){
          return 1;
      }
      if(i==N){
          return 0;
      }
    //   if(ind==0){
    //       if(sum%coins[0]==0) return 1;
    //       else return 0;
    //   }
      if(dp[i][currSum]!=-1) return dp[i][currSum];
      
     
      long long int take=0;
      if(coins[i]+currSum<=sum){
          take=solve(i,currSum+coins[i],coins,sum,N);
      }
      long long int not_take=solve(i+1,currSum,coins,sum,N);
      
      return dp[i][currSum]= take+not_take;
  }
    long long int count(int coins[], int N, int sum) {

        // code here.
        dp.resize(N,vector<int long long>(sum+1,-1));
        return solve(0,0,coins,sum,N);
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