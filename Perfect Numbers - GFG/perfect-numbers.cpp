//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        if(N==1) return 0;
        long sum = 1;
        // the reason is used to long i
        // because we do i*i which will make long long after product
        for(int i=2; 1LL*i*i<=N; i++){
            if(N%i==0){
                sum = sum + i;
                if(i!=N/i) sum = sum + N/i;
            }
        }
        return sum==N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends