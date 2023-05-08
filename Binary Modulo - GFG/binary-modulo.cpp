//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            int CalculatePowerWithMod=1;
            int ans=0;
            for(int i=s.length()-1;i>=0;i--){
                if(s[i]=='1'){
                    ans+=CalculatePowerWithMod;
                    ans%=m;
                }
                CalculatePowerWithMod*=2;
                CalculatePowerWithMod%=m;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends