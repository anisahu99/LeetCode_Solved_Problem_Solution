class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for(vector<int> &e:times){
            g[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans(n+1,INT_MAX);
        pq.push({0,k});
        ans[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;pq.pop();
            for(pair<int,int> &p:g[node]){
                int adj=p.first;
                int l=p.second;
                if(ans[adj]>d+l){
                    ans[adj]=d+l;
                    pq.push({d+l,adj});
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            res=max(ans[i],res);
        }
        return res==INT_MAX?-1:res;
    }
};