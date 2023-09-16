//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod=1e9+7;
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        if(n==1||n==2) return n;
        if(n==3) return 4;
        // your code here
        
        long long x1=1;
        long long x2=2;
        long long x3=4;
        for(int i=4;i<=n;i++){
            long long temp=(x3%mod+x2%mod+x1%mod)%mod;
            x1=x2;
            x2=x3;
            x3=temp;
        }
        return x3;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends