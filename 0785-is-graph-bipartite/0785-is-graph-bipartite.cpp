class Solution {
public:
    
    bool dfs(int node,vector<int>& color,vector<vector<int>>& graph){
        for(int &adj:graph[node]){
            if(color[adj]==-1){
                color[adj]=1-color[node];
                if(!dfs(adj,color,graph)) return false;
            }
            else if(color[adj]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,color,graph)) return false;
            }
        }
        return true;
    }
};