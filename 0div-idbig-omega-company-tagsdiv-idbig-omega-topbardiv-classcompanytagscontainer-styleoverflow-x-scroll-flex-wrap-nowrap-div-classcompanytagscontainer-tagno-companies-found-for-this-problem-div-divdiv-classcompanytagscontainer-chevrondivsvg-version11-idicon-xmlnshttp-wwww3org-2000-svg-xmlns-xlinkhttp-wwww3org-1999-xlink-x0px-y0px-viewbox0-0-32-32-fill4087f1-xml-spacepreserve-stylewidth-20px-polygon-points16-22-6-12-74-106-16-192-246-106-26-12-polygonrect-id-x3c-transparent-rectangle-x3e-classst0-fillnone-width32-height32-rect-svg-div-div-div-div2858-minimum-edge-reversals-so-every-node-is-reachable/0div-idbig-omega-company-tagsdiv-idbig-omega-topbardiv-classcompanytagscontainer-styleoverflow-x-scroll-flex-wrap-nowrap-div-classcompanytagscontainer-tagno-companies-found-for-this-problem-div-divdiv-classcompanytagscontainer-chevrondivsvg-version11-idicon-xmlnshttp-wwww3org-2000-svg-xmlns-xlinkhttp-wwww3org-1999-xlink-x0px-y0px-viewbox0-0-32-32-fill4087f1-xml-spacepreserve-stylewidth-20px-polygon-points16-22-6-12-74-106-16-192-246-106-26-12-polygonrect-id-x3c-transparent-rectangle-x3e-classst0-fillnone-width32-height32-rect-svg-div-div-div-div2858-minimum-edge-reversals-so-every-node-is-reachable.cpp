class Solution {
    vector<vector<int>> graph;
    vector<vector<int>> revGraph;
    
    map<pair<int, int>, int> dp;
    
    int dfs(int node, int parent) {
        int ans = 0;
        
        if(dp.find({node, parent}) != dp.end()){
            //cout<<"{ "<<node<<", "<<parent<<"} ="<<dp[{node,parent}]<<endl;
            return dp[{node, parent}];
        }
        
        for(auto &x:graph[node]) {
            if(x != parent)
                ans += dfs(x, node);
        }
        
        for(auto &x:revGraph[node]) {
            if(x != parent)
                ans += dfs(x, node) + 1;
        }
        //cout<<"{ "<<node<<", "<<parent<<"} ="<<ans<<endl;
        return dp[{node, parent}] = ans;
    }
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        graph = vector<vector<int>>(n);
        revGraph = vector<vector<int>>(n);
        dp.clear();
        
        for(auto x:edges) {
            graph[x[0]].push_back(x[1]);
            revGraph[x[1]].push_back(x[0]);
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            //cout<<i<<endl;
            ans.push_back(dfs(i, -1));
        }
        
        return ans;
    }
};