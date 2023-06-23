//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  vector<vector<int>>dp;
    int solve(int i,int j,string &s1,string &s2,int &x,int &y){
        
        if(i==x){
            return y-j;
        }
        
        if(j==y){
            return x-i;
        }
        
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=0;
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(i+1,j+1,s1,s2,x,y);
        }
        else{
            int insrt=1+solve(i,j+1,s1,s2,x,y);
            int rplc=1+solve(i+1,j+1,s1,s2,x,y);
            int delt=1+solve(i+1,j,s1,s2,x,y);
            
            ans=min(insrt,min(rplc,delt));
        }
        return dp[i][j]=ans;
    }
    int editDistance(string s, string t) {
        // Code here
        int x=s.length();
        int y=t.length();
        dp.resize(x,vector<int>(y,-1));
        return solve(0,0,s,t,x,y);
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