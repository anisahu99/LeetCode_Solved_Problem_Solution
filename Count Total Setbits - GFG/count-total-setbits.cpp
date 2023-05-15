//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  long long largest_power_of_2(long long N){
      long long x=0;
      while((1<<x)<=N){
          x++;
      }
      return (x-1);
  }
    long long countBits(long long N) {
        
        if(N==0)
        return 0;
        // code here
        long long x=largest_power_of_2(N);
        long long bitsupto2raisex=x*(1<<(x-1));
        long long msbfrom2rxton=N-(1<<x)+1;
        
        long long res=N-(1<<x);
        
        long long ans=bitsupto2raisex+msbfrom2rxton+countBits(res);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends