class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        
        queue<pair<int,int>> q;
        
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(!mat[row][col]){
                    ans[row][col]=0;
                    q.push({row,col});
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> cod=q.front();q.pop();
            
            for(int k=0;k<4;k++){
                int r=cod.first+dir[k].first;
                int c=cod.second+dir[k].second;
                if(r>=0&&r<m&&c>=0&&c<n&&ans[r][c]==-1){
                    ans[r][c]=1+ans[cod.first][cod.second];
                    q.push({r,c});
                }
            }
        }
        return ans;
    }
};