//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int columnNumber)
    {
        // your code here
        string s;
        
        while(columnNumber) {
            columnNumber--;
            
            long long int remain = columnNumber%26;
            char ch    = remain + 'A';
            s.push_back(ch);
            
            columnNumber /= 26;
            
        }
        
        reverse(begin(s), end(s));
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends