//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

bool check(unordered_map<char,int>& mp){
    for(auto it:mp){
        if(it.second>1) return true;
    }
    return false;
}
int longestSubstrDistinctChars (string s)
{
    // your code here
    unordered_map<char,int> mp;
    int i=0,j=0,n=s.length();
    int ans=0;
    while(j<n){
        mp[s[j]]++;
        while(i<j&&check(mp)){
            if(--mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        ans=max(ans,(int)mp.size());
        j++;
    }
    return ans;
}