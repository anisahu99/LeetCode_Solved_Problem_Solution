class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<vector<long long>>> adj(n);
        for(int i=0;i<n-1;i++){
            long long x1=bombs[i][0];
            long long y1=bombs[i][1];
            long long r1=bombs[i][2];
            for(int j=i+1;j<n;j++){
                long long x2=bombs[j][0];
                long long y2=bombs[j][1];
                long long r2=bombs[j][2];
                long long c1c2=((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
                adj[i].push_back({j,c1c2,r1*r1});
                adj[j].push_back({i,c1c2,r2*r2});
            }
        }
        vector<vector<int>> g(n);
        for(int i=0;i<n;i++){
            for(vector<long long> reach:adj[i]){
                if(reach[2]>=reach[1]){
                    g[i].push_back(reach[0]);
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            int cnt=1;
            queue<int> q;
            vector<int> vis(n,0);
            vis[i]=1;
            for(int next:g[i]){
                vis[next]=1;
                q.push(next);
                cnt++;
            }
            while(!q.empty()){
                int node=q.front();q.pop();
                for(int next:g[node]){
                    if(!vis[next]){
                        cnt++;
                        q.push(next);
                        vis[next]=1;
                    }
                }
            }
            mx=max(mx,cnt);
            if(mx==n)
                return mx;
        }
        return mx;
    }
};