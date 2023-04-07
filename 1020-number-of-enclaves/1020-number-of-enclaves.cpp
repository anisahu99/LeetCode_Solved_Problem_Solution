class Solution {
public:
    
    int m, n;
    void dfs(vector<vector<int>> &grid, int r, int c) {
        
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return;

        
        grid[r][c] = 0;
        
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if((row==0||row==m-1||col==0||col==n-1)&&grid[row][col]==1){
                    dfs(grid,row,col);
                }
            }
        }
        
        
        
        int count = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] == 1) {
                    count += 1;
                }
                
            }
        }
        
        return count;
    }
};