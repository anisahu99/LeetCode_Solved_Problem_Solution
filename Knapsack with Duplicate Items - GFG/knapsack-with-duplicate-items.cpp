//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    vector<vector<int>> dp;
    
    int solve(int idx,int lim,int W,int val[],int wt[],int N){
        
        if(idx>=N){
            return 0;
        }
        
        if(dp[idx][lim]!=-1){
            return dp[idx][lim];
        }
        
        int take=0;
        if(lim+wt[idx]<=W){
            take=val[idx]+solve(idx,lim+wt[idx],W,val,wt,N);
        }
        int not_take=0+solve(idx+1,lim,W,val,wt,N);
        
        return dp[idx][lim]=max(take,not_take);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        dp.resize(N, vector<int>(W+1, -1));
        return solve(0,0,W,val,wt,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends