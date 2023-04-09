class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.length();
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(vector<int>& edge:edges){
            indegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> t(n,vector<int>(26,0));
        int cnt=0;
        queue<int> q;
        for(int u=0;u<n;u++){
            if(indegree[u]==0){
                q.push(u);
                t[u][colors[u]-'a']=1;
            }
        }
        int ans=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            cnt++;
            ans=max(ans,t[u][colors[u]-'a']);
            for(int &v:adj[u]){
                for(int i=0;i<26;i++){
                    t[v][i]=max(t[v][i],t[u][i]+((colors[v]-'a')==i));
                }
                indegree[v]--;
                if(indegree[v]==0){
                    cnt++;
                    q.push(v);
                }
            }
        }
        if(cnt<n) 
            return -1;
        return ans;
    }
};