//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> dp;
    int solve(int idx,int lim,int W, int wt[], int val[], int n){
        if(idx>=n){
          //cout<<"hi"<<endl;
          return 0;  
        } 
        if(dp[idx][lim]!=-1){
            return dp[idx][lim];
        }
        int take=0;
        if(lim+wt[idx]<=W){
            //cout<<lim+wt[idx]<<endl;
            take=val[idx]+solve(idx+1,lim+wt[idx],W,wt,val,n);
        }
        int not_take=0+solve(idx+1,lim,W,wt,val,n);
        
        return dp[idx][lim]=max(take,not_take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       dp.resize(n,vector<int>(W+1,-1));
       return solve(0,0,W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends