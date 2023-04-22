//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int> res=arr;
        sort(arr.begin(),arr.end(),greater<int>());
        long long prefix=0;
        unordered_map<int,long long> mt;
        for(int i=0;i<n;i++){
            prefix+=arr[i];
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                prefix-=arr[i];
            }else{
                prefix-=arr[i];
                mt[arr[i]]=prefix;
            }
        }
        mt[arr[n-1]]=0;
        vector<long long> ans;
        for(int i=0;i<res.size();i++){
            ans.push_back(mt[res[i]]);
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends