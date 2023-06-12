//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int x[3]={0,1,-1};
    int y[3]={1,1,1};
    vector<vector<int>> dp;
    int solve(int row,int col,int n,int m,vector<vector<int>> &M){
        if(row<0||row>=n||col<0||col>=m){
            return 0;
        }
        if(col==m-1){
            return M[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        
        int ans=0;
        for(int k=0;k<3;k++){
            ans=max(ans,M[row][col]+solve(row+x[k],col+y[k],n,m,M));
        }
        return dp[row][col]=ans;
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int ans=0;
        dp.resize(n,vector<int>(m,-1));
        for(int row=0;row<n;row++){
            ans=max(ans,solve(row,0,n,m,M));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends