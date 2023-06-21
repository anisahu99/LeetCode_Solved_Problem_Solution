//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
     int solve(vector<int> &cuts,int L,vector<int> &dp){
        if(L==0){
            return 0;
        }
        if(L<0){
            return INT_MIN;
        }
        if(dp[L]!=-1){
            return dp[L];
        }
        int curr=INT_MIN;;
        for(int i=0;i<cuts.size();i++){
            curr=max(curr,solve(cuts,L-cuts[i],dp)+1);
        }
        return dp[L]=curr;
    }
    int maximizeTheCuts(int L, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(L+1,-1);
        vector<int> cuts;
        cuts.push_back(x);
        cuts.push_back(y);
        cuts.push_back(z);
        return solve(cuts,L,dp)<0?0:solve(cuts,L,dp);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends