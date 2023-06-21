//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    vector<vector<int>>dp;
    int solve(int i,int j,string &s1,string &s2,int &x,int &y){
        
        if(j>=y){
            return 0;
        }
        if(i>=x){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans1=0;
        int ans2=0;
        int ans3=0;
        if(s1[i]==s2[j]){
            ans1=1+solve(i+1,j+1,s1,s2,x,y);
        }
        else{
            ans2=0+solve(i,j+1,s1,s2,x,y);
            ans3=0+solve(i+1,j,s1,s2,x,y);
        }
        int ans=max(ans1,max(ans2,ans3));
        return dp[i][j]= ans;
    }
    int lcs(int &x, int &y, string &s1, string &s2)
    {
        // your code here
        dp.resize(x,vector<int>(y,-1));
        return solve(0,0,s1,s2,x,y);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends