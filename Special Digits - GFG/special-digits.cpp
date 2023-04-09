//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

long long mod = 1e9+7;
bool hogya=false;
long long factorial[100001];
long long mm[100001];
class Solution {
  public:
    void help(){
        factorial[0]=1;
        for(int i=1;i<=100000;i++){
            factorial[i] = (i*factorial[i-1])%mod;
        }
        mm[100000] = power(factorial[100000],mod-2);
        for(int i=99999;i>=0;i--){
            mm[i] = (mm[i+1]*(i+1))%mod;
        }
    }
    long long power(long long x,int y)
    {
        long long res = 1;
        x = x % mod;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % mod;
     
            y = y >> 1;
            x = (x * x) % mod;
        }
        return res;
    }
    int help2(int n,int r){
     
        return (factorial[n] * mm[r] % mod
                * mm[n - r] % mod)
               % mod;
    }
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
        bool hai=false;
        int i=0,sum;
        if(A==B){
            sum = N*A;
            while(sum!=0){
                int digit = sum%10;
                if(digit==C or digit==D){
                    hai=true;
                    break;
                }
                sum/=10;
            }
            if(hai)return 1;
            return 0;
        }
        if(hogya==false){
            help();
            hogya=true;
        }
        long long ans = 0;
        while(i<=N){
            sum = A*i+(B*(N-i));
            hai=false;
            while(sum!=0){
                int digit = sum%10;
                if(digit==C or digit==D){
                    hai=true;
                    break;
                }
                sum/=10;
            }
            if(hai==true){
                ans+=help2(N,i);
                ans%=mod;
            }
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends