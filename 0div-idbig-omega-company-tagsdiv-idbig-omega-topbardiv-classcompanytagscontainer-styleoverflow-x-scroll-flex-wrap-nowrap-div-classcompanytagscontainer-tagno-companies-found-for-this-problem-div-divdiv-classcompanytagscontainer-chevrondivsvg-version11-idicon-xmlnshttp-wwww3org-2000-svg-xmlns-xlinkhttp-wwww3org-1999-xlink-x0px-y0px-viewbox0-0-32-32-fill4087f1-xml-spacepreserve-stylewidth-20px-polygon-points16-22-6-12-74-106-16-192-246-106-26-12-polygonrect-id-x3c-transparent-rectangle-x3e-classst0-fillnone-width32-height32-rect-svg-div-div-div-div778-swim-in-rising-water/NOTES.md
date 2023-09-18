class Solution {
public:
typedef pair<int,int> P;
vector<P> dir{{1,0},{-1,0},{0,1},{0,-1}};
int solve(int row,int col,int &m,int &n,vector<vector<int>>& grid){
if(row==m-1&&col==n-1) return grid[row][col];
auto isSafe=[&](int x,int y){
return x>=0&&x<m&&y>=0&&y<n&&grid[x][y]!=-1;
};
int ans=INT_MAX;
int GRD=grid[row][col];
grid[row][col]=-1;
for(int k=0;k<4;k++){
int nr=row+dir[k].first;
int nc=col+dir[k].second;
if(isSafe(nr,nc)){
ans=min(ans,max(GRD,solve(nr,nc,m,n,grid)));
}
}
grid[row][col]=GRD;
return ans;
}
int swimInWater(vector<vector<int>>& grid) {
int m=grid.size(),n=grid[0].size();
return solve(0,0,m,n,grid);
}