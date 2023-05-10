class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(vector<int> &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        int ans=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            vector<int> res(n,INT_MAX);
            res[i]=0;
            pq.push({0,i});
            while(!pq.empty()){
                int d=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(pair<int,int> nbr:adj[node]){
                    int adjNode=nbr.first;
                    int wt=nbr.second;
                    if(d+wt<res[adjNode]){
                        pq.push({d+wt,adjNode});
                        res[adjNode]=d+wt;
                    }
                }
            }
            int cnt=0;
            for(int j=0;j<n;j++){
                if(res[j]<=distanceThreshold){
                    cnt++;
                }
            }
            //cout<<cnt<<endl;
            if(ans>=cnt){
                ans=cnt;
                idx=i;
            }
        }
        return idx;
    }
};