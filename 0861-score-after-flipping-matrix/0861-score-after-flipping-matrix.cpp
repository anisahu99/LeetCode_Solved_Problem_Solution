class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(col==0&&grid[row][col]){
                    break;
                }
                grid[row][col]=1-grid[row][col];
            }
        }
        for(int col=0;col<n;col++){
            int z=0,o=0;
            for(int row=0;row<m;row++){
                if(grid[row][col]){
                    o++;
                }else{
                    z++;
                }
            }
            if(z>o){
                for(int row=0;row<m;row++){
                    grid[row][col]=1-grid[row][col];
                }
            }
        }
        
        //
        int sum=0;
        for(int row=0;row<m;row++){
            for(int col=n-1;col>=0;col--){
                sum+=grid[row][col]*(1<<(n-1-col));
            }
        }
        return sum;
    }
};