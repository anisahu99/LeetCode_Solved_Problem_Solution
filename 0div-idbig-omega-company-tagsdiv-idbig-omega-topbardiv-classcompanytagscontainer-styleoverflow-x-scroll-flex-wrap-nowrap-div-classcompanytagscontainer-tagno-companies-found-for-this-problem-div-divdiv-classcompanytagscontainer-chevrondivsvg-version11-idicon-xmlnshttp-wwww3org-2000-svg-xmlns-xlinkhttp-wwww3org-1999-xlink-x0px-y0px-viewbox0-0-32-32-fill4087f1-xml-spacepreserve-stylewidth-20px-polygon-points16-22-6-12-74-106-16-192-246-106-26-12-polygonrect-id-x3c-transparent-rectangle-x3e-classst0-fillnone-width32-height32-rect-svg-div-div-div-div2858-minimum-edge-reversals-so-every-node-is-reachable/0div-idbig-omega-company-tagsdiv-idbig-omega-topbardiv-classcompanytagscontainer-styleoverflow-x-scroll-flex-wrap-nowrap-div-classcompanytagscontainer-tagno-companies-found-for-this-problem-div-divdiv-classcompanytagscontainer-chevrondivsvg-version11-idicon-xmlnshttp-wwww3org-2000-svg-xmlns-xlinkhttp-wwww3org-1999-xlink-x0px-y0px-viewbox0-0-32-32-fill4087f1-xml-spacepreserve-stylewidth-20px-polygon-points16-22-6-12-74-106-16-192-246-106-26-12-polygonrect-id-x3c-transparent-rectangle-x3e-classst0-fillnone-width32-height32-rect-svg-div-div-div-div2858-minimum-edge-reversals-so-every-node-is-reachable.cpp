class Solution {
public:
    //explanation video
    //https://www.youtube.com/watch?v=L8GJkBbAj8E
    typedef pair<int,int> P;
    vector<vector<P>> bi_direction_edge;
    int erc=0;
    void dfs(int node,int parent,int d,vector<int>& depth,vector<int> &cost,vector<int>& vis){
        vis[node]=1;
        depth[node]=d;
        for(auto &[next,price]:bi_direction_edge[node]){
            if(!vis[next]){
                cost[next]=price+cost[node];
                erc+=price;
                dfs(next,node,d+1,depth,cost,vis);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        bi_direction_edge.resize(n);
        for(vector<int> e:edges){
            bi_direction_edge[e[0]].push_back({e[1],0});
            bi_direction_edge[e[1]].push_back({e[0],1});
        }
        vector<int> cost(n);
        vector<int> depth(n);
        vector<int> vis(n);
        dfs(0,-1,0,depth,cost,vis);
        vector<int> ans(n);
        ans[0]=erc;
        for(int i=1;i<n;i++){
            int val1=abs(depth[i]-cost[i]);
            int val2=erc-cost[i];
            ans[i]=val1+val2;
        }
        return ans;
    }
};