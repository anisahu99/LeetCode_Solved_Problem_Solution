//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{

  public:
  int sum;
  vector<vector<int>> dp;
    int solve(int i,int diff,int n,int arr[]){
        if(i==n){
            return abs(diff);
        }
        if(dp[i][sum+diff]!=-1){
            //cout<<"Hi"<<endl;
            return dp[i][sum+diff];
        }
        //cout<<diff+sum<<endl;
        int add_in_l1=INT_MAX;
        int add_in_l2=INT_MAX;
        add_in_l1=min(add_in_l1,solve(i+1,diff+arr[i],n,arr));
        add_in_l2=min(add_in_l2,solve(i+1,diff-arr[i],n,arr));
        
        return dp[i][sum+diff]=min(add_in_l1,add_in_l2);
        //return min(add_in_l1,add_in_l2);
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    dp.resize(n+1,vector<int>(2*sum+2,-1));
	    return solve(0,0,n,arr);
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends