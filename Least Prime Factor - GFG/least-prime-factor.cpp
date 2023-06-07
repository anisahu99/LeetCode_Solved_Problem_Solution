//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> p(n+1);
        vector<int> ans(n+1);
        ans[0]=0;ans[1]=1;ans[2]=2;
        for(int i=3;i<=n;i=i+2){
            p[i]=1;
        }
        p[2]=1;
        for(int i=2;i<=n;i=i+2){
            if(p[i]){
                ans[i]=i;
                for(int j=i*2;j<=n;j=j+i){
                    ans[j]=i;
                    p[j]=0;
                }
            }
        }
        for(int i=3;i<=n;i=i+2){
            if(p[i]){
                ans[i]=i;
                for(int j=i*2;j<=n;j=j+i){
                    if(ans[j]==0){
                        ans[j]=i;
                    }
                    
                    p[j]=0;
                }
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
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends