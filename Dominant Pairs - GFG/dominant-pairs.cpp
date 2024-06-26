//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int binarySearch(vector<int> &arr,int key,int n){
        int low = n/2, high = n-1, mid, index=-1;
        while(low<=high){
            mid = (low+high)/2;
            if(5*arr[mid]<=key){
                index=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return index;
    }
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        sort(arr.begin()+n/2,arr.end());
        int ans=0;
        for(int i=0;i<n/2;i++){
            int index = binarySearch(arr,arr[i],n);
            if(index!=-1)ans+=(index-n/2)+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends