class Solution {
public:
    vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;
    void dfs(int row,int col,vector<vector<int>>& grid){
        if(row<0||row==m||col<0||col==n||grid[row][col]==0||grid[row][col]==3) return;
        
        grid[row][col]=3;
        
        for(int k=0;k<4;k++){
            dfs(row+dir[k].first,col+dir[k].second,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0||row==m-1||col==0||col==n-1&&grid[row][col]==1){
                    dfs(row,col,grid);
                }
            }
        }
        int cnt=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};