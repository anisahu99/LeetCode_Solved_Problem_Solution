//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int X){
        // code here
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(cnt==0&&s[i]!='0')
                {
                    cnt=X;
                }
                cnt--;
            }
            else if(s[i]=='1')
            {
                if(cnt<(-X))
                {
                    return false;
                }
                else
                {
                    cnt=X;
                }
            }
        }
        if(cnt<0)
        {
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends