//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int>arr, int sum , int n ,vector<vector<int>>& dp){
        if(sum==0){
            return true;
        }
        if(n<0){
            return false;
        }
        if(dp[n][sum]!=-10){
            return dp[n][sum];
        }
        
        int inc =0;
        
        if(sum>=arr[n]){
            inc = solve(arr , sum-arr[n] , n-1 , dp);
        }
        
        int exc = solve(arr , sum , n-1 , dp);
        
        dp[n][sum] = inc || exc;
        return dp[n][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n , vector<int>(sum+1 , -10));
        
        return solve(arr , sum , n-1 , dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends