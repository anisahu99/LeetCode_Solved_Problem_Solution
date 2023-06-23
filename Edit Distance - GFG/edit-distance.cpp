//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int solveTab(string &s1,string &s2,int x,int y){
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        
        for(int j=0;j<y;j++){
            dp[x][j]=y-j;
        }
        for(int i=0;i<x;i++){
            dp[i][y]=x-i;
        }
        
        for(int i=x-1;i>=0;i--){
            for(int j=y-1;j>=0;j--){
                int ans=0;
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    int insrt=1+dp[i][j+1];
                    int rplc=1+dp[i+1][j+1];
                    int delt=1+dp[i+1][j];
                    
                    ans=min(insrt,min(rplc,delt));
                    dp[i][j]=ans;
                }
                
            }
        }
        return dp[0][0];
    }
    int editDistance(string s, string t) {
        // Code here
        int x=s.length();
        int y=t.length();
        return solveTab(s,t,x,y);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends