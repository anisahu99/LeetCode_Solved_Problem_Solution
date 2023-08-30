class Solution {
public:
    
    vector<vector<int>> res;
    
    void dfs(int node,int parent,int time,vector<int> &dis,vector<int>& low,vector<int> &vis,vector<vector<int>> &g){
        
        vis[node]=1;
        dis[node]=time;
        low[node]=time;
        for(int nbr:g[node]){
            if(nbr==parent) continue;
            
            if(vis[nbr]){
                low[node]=min(low[node],low[nbr]);
                continue;
            }
            
            dfs(nbr,node,time+1,dis,low,vis,g);
            low[node]=min(low[node],low[nbr]);
            
            if(dis[node]<low[nbr]){
                res.push_back({node,nbr});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for(vector<int>& c:connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        vector<int> dis(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        dfs(0,-1,1,dis,low,vis,g);
        return res;
    }
};