class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(vector<int>& e:flights){
            g[e[0]].push_back({e[1],e[2]});
        }
        //{price,{node,stops}}
        
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        int level=0;
        while(!q.empty()&&level<=k){
            int sz=q.size();
            while(sz--){
                int node=q.front().first;
                int cost=q.front().second;q.pop();
                for(pair<int,int> &next:g[node]){
                    if(dist[next.first]>cost+next.second){
                        dist[next.first]=cost+next.second;
                        q.push({next.first,dist[next.first]});
                    }
                }
            }
            level++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};