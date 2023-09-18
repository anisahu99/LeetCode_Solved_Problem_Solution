class Solution {
public:
    //1631. Path With Minimum Effort
    //use this question concept to reach the destination
    typedef pair<int,pair<int,int>> P;
    vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<P>> g(m*n);
        priority_queue<P,vector<P>,greater<P>> pq;
        int ans=0;
        pq.push({0,{0,0}});
        auto isSafe=[&](int x,int y){
            return x>=0&&x<m&&y>=0&&y<n&&grid[x][y]!=-1;
        };
        while(!pq.empty()){
            int t=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;pq.pop();
            ans=max(ans,t);
            if(row==m-1&&col==n-1) return ans;
            int GRD=grid[row][col];
            grid[row][col]=-1;// to make visited
            for(int k=0;k<4;k++){
                int nr=row+dir[k].first;
                int nc=col+dir[k].second;
                if(isSafe(nr,nc)){
                    pq.push({max(GRD,grid[nr][nc]),{nr,nc}});
                }   
            }
        }
        return ans;
    }
};