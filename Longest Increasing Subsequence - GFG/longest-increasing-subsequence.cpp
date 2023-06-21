//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int solveOptimal(int arr[],int n){
        if(n==0) return 0;
        
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[index]=arr[i];
            }
        }
        return ans.size();
    }
    
    
    int longestSubsequence(int n, int arr[])
    {
       // your code here
    
    return solveOptimal(arr,n);
    }

};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends