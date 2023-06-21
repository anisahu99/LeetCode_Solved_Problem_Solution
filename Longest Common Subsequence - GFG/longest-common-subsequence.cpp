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
    int solveTab(int &x, int &y, string &s1, string &s2){
        

        vector<int> curr1(y+1,0);

        vector<int> next1(y+1,0);
        
        for(int i=x-1;i>=0;i--){
            for(int j=y-1;j>=0;j--){
                int ans1=0;
                int ans2=0;
                int ans3=0;
                if(s1[i]==s2[j]){
                    ans1=1+next1[j+1];
                }
                else{
                    ans2=0+curr1[j+1];
                    ans3=0+next1[j];
                }
                int ans=max(ans1,max(ans2,ans3));
                curr1[j]= ans;
            }
            next1=curr1;
        }
        return next1[0];
    }
    int lcs(int &x, int &y, string &s1, string &s2)
    {
        // your code here
        
        return solveTab(x,y,s1,s2);
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