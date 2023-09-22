//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int low=0,high=n-1;
        int in=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                in=mid;
                high=mid-1;
            }
            if(arr[mid]>x) high=mid-1;
            if(arr[mid]<x) low=mid+1;
          
        }
        low=0,high=n-1;
        int in1=-1;
          while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==x){
                in1=mid;
                low=mid+1;
            }
            if(arr[mid]>x) high=mid-1;
            if(arr[mid]<x) low=mid+1;
           
        }
     return {in,in1};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends