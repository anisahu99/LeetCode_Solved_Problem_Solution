class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<pair<int,int>>> graph(n); //pair.first=node, pair.second=color of edge
        for(auto v:red_edges){
            graph[v[0]].push_back({v[1],0}); //0 for red edge
        }
        
        for(auto v:blue_edges){
            graph[v[0]].push_back({v[1],1});
        }
        vector<int> dist(n,-1);
        dist[0]=0;
        vector<vector<int>> vis(n,vector<int>(2));
        queue<vector<int>> q;
        q.push({0,0,-1}); //start node,dist,color
        vis[0][0]=1;
        vis[0][1]=1;
        
        while(!q.empty()){
            vector<int> temp=q.front(); q.pop();
            int node=temp[0],steps=temp[1],prev_color=temp[2];
            
            for(auto& [neighbour,color]:graph[node]){
                if(!vis[neighbour][color]&&color!=prev_color){
                    vis[neighbour][color]=1;
                    q.push({neighbour,1+steps,color});
                    if(dist[neighbour]==-1){
                        dist[neighbour]=1+steps;
                    }
                }
            }
        }
        return dist;
    }
};