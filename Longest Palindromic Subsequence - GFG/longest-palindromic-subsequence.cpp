//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<int>>dp;
    int lcs(int i,int j,string &s1,string &s2){
        
        if(j==s2.length()){
            return 0;
        }
        if(i==s1.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans1=0;
        int ans2=0;
        int ans3=0;
        if(s1[i]==s2[j]){
            ans1=1+lcs(i+1,j+1,s1,s2);
        }
        else{
            ans2=0+lcs(i,j+1,s1,s2);
            ans3=0+lcs(i+1,j,s1,s2);
        }
        int ans=max(ans1,max(ans2,ans3));
        return dp[i][j]= ans;
    }
    int longestPalinSubseq(string &A) {
        //code here
        string s2=A;
        reverse(s2.begin(),s2.end());
        dp.resize(A.length(),vector<int>(A.length(),-1));
        return lcs(0,0,A,s2);
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends