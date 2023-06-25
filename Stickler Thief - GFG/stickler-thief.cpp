//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    vector<int> dp;
    int solve(int i,int arr[],int n){
        
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int ans1=arr[i]+solve(i+2,arr,n);
        int ans2=0+solve(i+1,arr,n);
        
        return dp[i]=max(ans1,ans2);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        dp.resize(n,-1);
        return solve(0,arr,n);
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