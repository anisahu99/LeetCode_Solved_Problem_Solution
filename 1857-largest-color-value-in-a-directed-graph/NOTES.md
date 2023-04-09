}
}
else if(inRec[next]){
return false;
}
}
inRec[node]=0;
return true;
}
int largestPathValue(string& colors, vector<vector<int>>& edges) {
int n=edges.size();
vector<vector<int>> adj(n);
vector<int> vis(n,0);
vector<int> inRec(n,0);
unordered_map<char,int>mt;
for(vector<int> &edge:edges){
adj[edge[0]].push_back(edge[1]);
}
for(int i=0;i<n;i++){
if(!vis[i]){
if(!dfs(i,colors,mt,inRec,vis,adj)){
return -1;
}
}
}
return ans;
}
};