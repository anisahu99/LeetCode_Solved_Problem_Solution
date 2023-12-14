class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<pair<int,int>> row(m),col(n);
        
        for(int i=0;i<m;i++){
            int zero=0;
            int one=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    one++;
                    col[j]={col[j].first+1,col[j].second};
                }
                else{
                    zero++;
                    col[j]={col[j].first,col[j].second+1};
                }
            }
            row[i]={one,zero};
        }
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=row[i].first+col[j].first-row[i].second-col[j].second;
            }
        }
        
        return ans;
    }
};