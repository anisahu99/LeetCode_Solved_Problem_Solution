//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solveTab(int arr[],int n){
        vector<int> dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            int ans1=arr[i]+dp[i+2];
            int ans2=0+dp[i+1];
            dp[i]=max({ans1,ans2});
        }
        
        return dp[0];
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        
        return solveTab(arr,n);
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