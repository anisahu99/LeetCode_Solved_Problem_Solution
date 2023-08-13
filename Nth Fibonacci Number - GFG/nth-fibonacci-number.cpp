//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod=1e9+7;
    int nthFibonacci(int n){
        // code here
        if(n==0||n==1) return 1;
        int second_prev=0;
        int first_prev=1;
        for(int i=2;i<=n;i++){
            int curr=first_prev+second_prev;
            second_prev=first_prev;
            first_prev=curr%mod;
        }
        return first_prev;
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends