class Solution {
public:
    const int mod=1e9+7;
    int binaryExponentiation(int a,int b){
        int ans=1;
        while(b){

            if(b&1){
                ans=(1LL*ans*a)%mod;
            }
            a=(1LL*a*a)%mod;
            b>>=1;
        }
        return ans;
    }
    
    int fact(int n){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=(1LL*ans*i)%mod;
        }
        return ans;
    }
    
    int nCr(int n,int r){
        int numer=fact(n);
        int denom=(1LL*fact(r)*fact(n-r))%mod;
        return (1LL*numer*binaryExponentiation(denom,mod-2))%mod;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if(k>26) return 0;
        vector<int> freq(26);
        for(char ch:s){
            freq[ch-'a']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }
        if(pq.size()<k) return 0;
        
        int res=1;
        while(k>0){
            int countEqualFreq=0,freq=pq.top();
            while(pq.size()&&pq.top()==freq){
                countEqualFreq++;
                pq.pop();
            }
            
            if(countEqualFreq<=k){
                k-=countEqualFreq;
                res=(1LL*res*binaryExponentiation(freq,countEqualFreq))%mod;
            }else{
                res=(1LL*res*nCr(countEqualFreq,k))%mod;
                res=(1LL*res*binaryExponentiation(freq,k))%mod;
                break;
            }
        }
        return res;
    }
};