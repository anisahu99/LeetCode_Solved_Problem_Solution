//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int n=s.size();
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!='?' && s[j]!='?' && s[i]!=s[j]){
                return -1;
            }
            if(s[i]=='?' && s[j]!='?'){
                s[i]=s[j];
            }
            else if(s[i]!='?' && s[j]=='?'){
                s[j]=s[i];
            }
            else if(i!=0 && s[i-1]!='?' &&  s[i]=='?' && s[j]=='?' ){
                s[i]=s[i-1];
                s[j]=s[j+1];
            }
            i++;
            j--;
        }
        int ans=0;
        for(int i=1;i<=n/2;i++){
            if(s[i]=='?'){
                continue;
            }
            if(s[i-1]!='?'){
                ans+=(2*abs(s[i]-s[i-1]));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends