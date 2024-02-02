class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> adj(n);
        
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        q.push({headID,0});
        int time=0;
        while(!q.empty()){
            int node=q.front().first;
            int t=q.front().second;q.pop();
            for(int child:adj[node]){
                q.push({child,t+informTime[node]});
                time=max(time,t+informTime[node]);
            }
            
        }
        return time;
    }
};