//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int mod=1e9+7;
	
	vector<int> dp;
	    
	    int solve(int ind,string& str,int &n)
    {
         if(ind==n) return 1;
         
         if(dp[ind]!=-1) return dp[ind];
         
         int onech=0,twoch=0;
         if(str[ind]>='1' && str[ind]<='9') 
         {
             onech=solve(ind+1,str,n)%mod;
         }
         string temp=str.substr(ind,2);
         if(ind<n-1 && temp>="10" && temp<="26")
         {
             twoch=solve(ind+2,str,n)%mod;
         }
         return dp[ind]=(onech+twoch)%mod;
    }
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    dp.resize(n,-1);
		    return solve(0,str,n);
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends