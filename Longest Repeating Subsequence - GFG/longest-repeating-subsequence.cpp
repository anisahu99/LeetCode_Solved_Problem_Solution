//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int n;
	    vector<vector<int>> dp;
	    int solve(int i,int j,string &str){
	        if(i==n||j==n){
	            return 0;
	        }
	        if(dp[i][j]!=-1){
	            return dp[i][j];
	        }
	        
	        if(i!=j&&str[i]==str[j]){
	            return dp[i][j]=(1+solve(i+1,j+1,str));
	        }
	        
	        return dp[i][j]=max(solve(i,j+1,str),(solve(i+1,j,str)));
	        
	    }
		int LongestRepeatingSubsequence(string &str){
		    // Code here
		    n=str.length();
		    dp.resize(n+1,vector<int>(n+1,-1));
		    return solve(0,0,str);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends