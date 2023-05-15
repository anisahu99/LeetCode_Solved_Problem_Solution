class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n<=0) return {};
        if(n==1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(vector<int>& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        vector<int> ans;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        while(n>2){
            int sz=q.size();
            n-=sz;
            while(sz--){
                int node=q.front();q.pop();
                for(int next:adj[node]){
                    degree[next]--;
                    if(degree[next]==1){
                        q.push(next);
                    }
                }
            }
        }
        while(!q.empty()){
            int node=q.front();q.pop();
            ans.push_back(node);
        }
        
        return ans;;
    }
};