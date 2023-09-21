//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
     int solve(vector<int> &dp,int arr[],int i,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int taken = solve(dp,arr,i+2,n) + arr[i];
        int not_taken = solve(dp,arr,i+1,n);
        
        dp[i] = max(taken,not_taken);
        
        return dp[i];
    }
    
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n+1,-1);
        
        int ans = solve(dp,arr,0,n);
        
        return ans;
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends