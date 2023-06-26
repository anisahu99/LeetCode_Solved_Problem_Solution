//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1e9+7;
    int nCr(int n, int r){
        // code here
        if(n<r) return 0;
        if(n==r) return 1;
        vector<vector<int>> pascal;
        pascal.push_back({1});
        for(int i=1;i<=n;i++){
            vector<int> v(i+1,1);
            for(int j=1;j<i;j++){
                if(j-1>=0&&j>=0){
                    v[j]=(pascal[i-1][j-1]%mod+pascal[i-1][j]%mod)%mod;
                }
            }
            pascal.push_back(v);
        }
        return pascal[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends