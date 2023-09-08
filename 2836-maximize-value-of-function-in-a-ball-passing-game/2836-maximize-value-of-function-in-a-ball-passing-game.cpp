# define ll long long;
class Solution {
public:
    //https://www.youtube.com/watch?v=eVrB_4K5wcs
    // Binary Lifting || Leetcode Weekly Contest 360 
    
    long long getScore(int id,int par,long long k,vector<vector<pair<int,long long>>> &dp){
        if(par==-1) return 0;
        if((k&(1LL<<par))==0){
            return getScore(id,par-1,k,dp);
        }
        
        return dp[par][id].second+getScore(dp[par][id].first,par-1,k,dp);
    }
    
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int m=40;  //log2(10^10)
        int n=receiver.size();
        vector<vector<pair<int,long long>>> dp(m,vector<pair<int,long long>>(n));//parent level,score
        //binary lifting
        for(int i=0;i<n;i++){
            dp[0][i]={receiver[i],receiver[i]}; // {parent,score}// at 2^0=1
        }
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int x=dp[j-1][i].first;
                dp[j][i]={dp[j-1][x].first,dp[j-1][i].second+dp[j-1][x].second};
            }
        }
        long long res=0;
        for(int id=0;id<n;id++){
            res=max(res,id+getScore(id,m-1,k,dp));
        }
        return res;
    }
};