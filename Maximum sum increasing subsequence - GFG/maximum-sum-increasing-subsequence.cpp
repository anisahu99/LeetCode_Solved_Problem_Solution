//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	vector<vector<int>> dp;
	int solve(int i,int preIdx,int arr[],int n){
	    if(i==n){
	        return 0;
	    }
	    if(dp[i][preIdx+1]!=-1){
	        return dp[i][preIdx+1];
	    }
	    int take=0;
	    if(preIdx==-1||arr[i]>arr[preIdx]){
	        take=arr[i]+solve(i+1,i,arr,n);
	    }
	    int not_take=solve(i+1,preIdx,arr,n);
	    
	    return dp[i][preIdx+1]=max(take,not_take);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    dp.resize(n,vector<int>(n+1,-1));
	    return solve(0,-1,arr,n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends