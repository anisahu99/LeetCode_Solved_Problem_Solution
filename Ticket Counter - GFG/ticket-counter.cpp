//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        int firstKRem = 0;
        bool left2Right = 1;
        
        while(N-firstKRem > K) {
            // remove first K
            firstKRem += K;
            left2Right = !left2Right;
            
            // remove last K
            if(N-firstKRem > K) {
                N -= K;
                left2Right = !left2Right;
            }
        }
        
        if(left2Right)
            return N;
            
        return firstKRem+1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends