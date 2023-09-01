class Solution {
public:
int mod=1e9+7;
vector<int> shortestPath(int &n,vector<vector<pair<int,int>>> &g){
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<int> dis(n,INT_MAX);
dis[0]=0;
pq.push({0,0});
int cnt=0;
while(!pq.empty()){
int node=pq.top().second;
int d=pq.top().first;pq.pop();
for(pair<int,int> &p:g[node]){
if(dis[p.first]>=d+p.second){
dis[p.first]=d+p.second;
pq.push({dis[p.first],p.first});
}
}
}
return dis;
}
int countPaths(int n, vector<vector<int>>& roads) {
vector<vector<pair<int,int>>> g(n);
for(vector<int>& e:roads){
g[e[0]].push_back({e[1],e[2]});
g[e[1]].push_back({e[0],e[2]});
}
vector<int> dist=shortestPath(n,g);
return dfs(0,n,dist,g);
}
};