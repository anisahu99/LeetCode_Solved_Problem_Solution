class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;
    int solve(int i1,int j1,vector<vector<int>>& grid,int j2){
        int i2=i1;
        if(i1<0||i1>=m||j1<0||j1>=n||i2<0||i2>=m||j2<0||j2>=n)
            return INT_MIN;
        if(dp[i1][j1][j2]!=-1){
            return dp[i1][j1][j2];
        }
        if(i1==m-1&&i2==m-1){
            if(j1==j2){
            return grid[i1][j1];
        }
        else
            return (grid[i1][j1]+grid[i2][j2]);
        }
        
        int ans=0;
        if(j1==j2){
            ans+=grid[i1][j1];
        }
        else
            ans+=grid[i1][j1]+grid[i2][j2];
        int max_ans=0;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    max_ans=max(max_ans,solve(i1+1,j1+i,grid,j2+j));
                }
            }
        return dp[i1][j1][j2]=ans+max_ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();
        int s=75;
        dp.resize(s,vector<vector<int>>(s,vector<int>(s,-1)));
        return solve(0,0,grid,n-1);
    }
};