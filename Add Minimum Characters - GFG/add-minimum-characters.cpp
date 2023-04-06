//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str)
{
    // code here
    int n = str.size();
    int t = 0;
    int e = n - 1;
    int e2 = e;
    int count = 0;
    while (t < e)
    {
        if (str[t] == str[e])
        {
            t++;
            e--;
        }
        else
        {
            count++;
            t = 0;
            e2--;
            e = e2;
        }
    }
    return count;
}
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends