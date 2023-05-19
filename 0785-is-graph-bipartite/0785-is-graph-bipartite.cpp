class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<int,int>> q;
        vector<int> vis(n);
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push({i,1});
                color[i]=1;
            }
            while(!q.empty()){
                int node=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int next:graph[node]){
                    if(!vis[next]){
                        q.push({next,1-col});
                        color[next]=1-col;
                        vis[next]=1;
                    }
                    else if(vis[next]&&color[next]!=(1-col)){
                        return false;
                    }
                    
                }
            }
        }
        return true;
    }
};