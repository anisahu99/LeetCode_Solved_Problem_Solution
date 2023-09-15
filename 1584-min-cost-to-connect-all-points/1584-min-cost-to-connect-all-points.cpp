class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y,int p_x,int p_y) {        
        if(p_x != p_y) {
            if(rank[p_x] > rank[p_y]) {
                parent[p_y] = p_x;
            } else if(rank[p_y] > rank[p_x]) {
                parent[p_x] = p_y;
            } else {
                parent[p_y] = p_x;
                rank[p_x]++;
            }
        }
    }
    static bool cmp( vector<int> &v1,vector<int> &v2){
        return v1[0]<v2[0];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i<n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        vector<vector<int>> edges;
        for(int i=0;i<n-1;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int wt=abs(x1-x2)+abs(y1-y2);
                edges.push_back({wt,i,j});
            }
        }
        sort(edges.begin(),edges.end(),cmp);
        
        int sum=0;
        for(vector<int>& edge:edges){
            int p_x=find(edge[1]);
            int p_y=find(edge[2]);
            if(p_x!=p_y){
                Union(edge[1],edge[2],p_x,p_y);
                sum+=edge[0];
            }
        }
        
        return sum;
    }
};



// for(vector<int> &edge:edges){
        //     cout<<"("<<edge[0]<<","<<edge[1]<<","<<edge[2]<<")"<<endl;
        // }