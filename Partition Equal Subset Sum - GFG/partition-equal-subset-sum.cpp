//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int solve(int i,int target,int arr[],int N){
        if(target==0){
            return 1;
        }
        if(i==N){
            return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int take=solve(i+1,target-arr[i],arr,N);
        
        if(take){
            dp[i][target]=1;
            return 1;
        }
        int not_take=solve(i+1,target,arr,N);
        
        if(not_take){
            dp[i][target]=1;
            return 1;
        }
        dp[i][target]=0;
        return 0;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int totalSum=0;
        for(int i=0;i<N;i++){
            totalSum+=arr[i];
        }
        if(totalSum&1){
            return 0;
        }
        dp.resize(N,vector<int>(totalSum/2+1,-1));
        return solve(0,totalSum/2,arr,N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends