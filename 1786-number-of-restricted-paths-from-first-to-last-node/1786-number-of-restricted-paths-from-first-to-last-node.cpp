class Solution {
public:
    int mod=1e9+7;
    vector<int> dp;
    int solve(int node,int n,vector<int> &res,vector<vector<pair<int,int>>> &adj){
        
        if(node==n){
            return 1;
        }
        if(dp[node]!=-1){
            //cout<<dp[node]<<endl;
            return dp[node];
        }
        
        int ans=0;
        for(pair<int,int> nbr:adj[node]){
            if(res[node]>res[nbr.first]){
                ans=ans%mod;
                ans=ans+solve(nbr.first,n,res,adj);
                ans=ans%mod;
            }
        }
        ans=ans%mod;
        return dp[node]=ans;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(vector<int>& edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> res(n+1,INT_MAX);
        res[n]=0;
        pq.push({0,n});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;pq.pop();
            for(pair<int,int> &nbr:adj[node]){
                int adj=nbr.first;
                int wt=nbr.second;
                if(d+wt<res[adj]){
                    res[adj]=d+wt;
                    pq.push({d+wt,adj});
                }
            }
        }
        dp.resize(n+1,-1);
        return solve(1,n,res,adj);
        
    }
};