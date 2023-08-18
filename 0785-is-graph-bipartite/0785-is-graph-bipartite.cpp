class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push({i,0});
                while(!q.empty()){
                    int node=q.front().first;
                    int c=q.front().second;q.pop();
                    for(int &adj:graph[node]){
                        if(color[adj]==-1){
                            color[adj]=1-c;
                            q.push({adj,1-c});
                        }
                        else if(color[adj]==c) return false;
                    }
                }
            }
        }
        return true;
    }
};