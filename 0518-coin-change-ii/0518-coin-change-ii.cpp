class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int currSum,vector<int> &coins,int &amount,int n){
      if(currSum==amount){
          return 1;
      }
      if(i==n){
          return 0;
      }
      if(dp[i][currSum]!=-1) return dp[i][currSum];


      int take=0;
      if(coins[i]+currSum<=amount){
          take=solve(i,currSum+coins[i],coins,amount,n);
      }
      int not_take=solve(i+1,currSum,coins,amount,n);

      return dp[i][currSum]= take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return solve(0,0,coins,amount,n);
    }
};