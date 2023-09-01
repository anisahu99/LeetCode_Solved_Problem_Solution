class Solution {
public:
    int mod=1e9+7;
    vector<long long> shortestPath(int &n,vector<vector<pair<long long,long long>>> &g){
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<long long> dis(n,LLONG_MAX);
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            long long node=pq.top().second;
            long long d=pq.top().first;pq.pop();
            for(pair<long long,long long> &p:g[node]){
                if(dis[p.first]>d+p.second){
                    dis[p.first]=d+p.second;
                    pq.push({d+p.second,p.first});
                }
            }
        }
        return dis;
    }
    
    vector<long long> t;
    
    int dfs(int node,int &n,vector<long long> &dist,vector<vector<pair<long long,long long>>> &g){
        if(node==n-1) return 1;
        if(t[node]!=-1) return t[node];
        
        long long ans=0;
        
        for(pair<long long,long long> &p:g[node]){
            long long wt=p.second;
            long long v=p.first;
            if(dist[node]+wt==dist[v]){
                ans=(ans%mod+dfs(v,n,dist,g)%mod)%mod;
            }
        }
        return t[node]=ans;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> g(n);
        for(vector<int>& e:roads){
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        vector<long long> dist=shortestPath(n,g);
        t.resize(n,-1);
        
        return dfs(0,n,dist,g);
    }
};