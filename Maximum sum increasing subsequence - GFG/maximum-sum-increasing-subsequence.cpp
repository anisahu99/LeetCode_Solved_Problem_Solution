//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solveTab(int arr[],int n){
	    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	    for(int i=n-1;i>=0;i--){
	        for(int j=i-1;j>=-1;j--){
	            int take=0;
        	    if(j==-1||arr[i]>arr[j]){
        	        take=arr[i]+dp[i+1][i+1];
        	    }
        	    int not_take=not_take=dp[i+1][j+1];
        	    dp[i][j+1]=max(take,not_take);
	        }
	    }
	    return dp[0][0];
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    return solveTab(arr,n);
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