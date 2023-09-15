//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solveTab(int target,int N,int arr[]){
        vector<vector<int>> dp(N+1,vector<int>(target+1,0));
        
        vector<int> curr(target+1,0);
        vector<int> next(target+1,0);
        
        curr[0]=1;
        next[0]=1;
        
        for(int i=N-1;i>=0;i--){
            for(int t=0;t<=target;t++){
                
                int take=0;
                if(t-arr[i]>=0){
                    take=next[t-arr[i]];
                }
                
                int not_take=next[t];
                
                curr[t]=take or not_take;
            }
            next=curr;
            
        }
        return next[target];
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
        return solveTab(totalSum/2,N,arr);
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