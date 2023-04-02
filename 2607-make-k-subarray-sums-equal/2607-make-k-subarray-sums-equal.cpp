class Solution {
public:
    long long solve(vector<int>& v){
        int n=v.size();
        long long ans=0;
        if(n%2==0){
            int median=v[n/2];
            for(long long i:v){
                long long f=abs(i-median);
                ans+=f;
            }
            median=v[(n-1)/2];
            long long ans2=0;
            for(long long i:v){
                long long f=abs(i-median);
                ans2+=f;
            }
            return min(ans,ans2);
        }else{
            int median=v[n/2];
            for(long long i:v){
                long long f=abs(i-median);
                ans+=f;
            }
            return ans;
        }
        return 0;
    }
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans=0;
        k=long(k);
        int n=arr.size();
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            vector<int> v;
            long long j=i;
            while(true){
                if(vis[j%n]==1) break;
                vis[j%n]=1;
                v.push_back(arr[j%n]);
                j+=k;
            }
            if((int)v.size()){
                sort(v.begin(),v.end());
                ans+=solve(v);
            }
        }
        return ans;
    }
};