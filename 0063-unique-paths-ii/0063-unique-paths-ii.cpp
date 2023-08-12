class Solution {
public:
    int m,n;
    vector<vector<int>> t;
    int dfs(int row,int col,vector<vector<int>>& obstacleGrid){
        if(row<0||row==m||col<0||col==n||obstacleGrid[row][col]) return 0;
        if(row==m-1&&col==n-1) return 1;
        if(t[row][col]!=-1) return t[row][col];
        int right=dfs(row,col+1,obstacleGrid);
        int down=dfs(row+1,col,obstacleGrid);
        
        return t[row][col]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        t.resize(m,vector<int>(n,-1));
        return dfs(0,0,obstacleGrid);
    }
};