
class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n-1;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int wt=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,wt});
			    adj[j].push_back({i,wt});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int cost=0;
        vector<int> vis(n,0);
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]) {
                continue;
            }
            
            vis[node] = true;
            cost+=d;
            for(pair<int,int> nbr:adj[node]){
                int adjNode=nbr.first;
                int wt=nbr.second;
                pq.push({wt,adjNode});
            }
        }
        return cost;
    }
};