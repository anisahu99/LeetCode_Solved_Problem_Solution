class Solution {
public:
    vector<vector<int>> d{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int bfs(int &n,vector<vector<int>>& grid){
        if(grid[0][0]) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int cnt=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int row=q.front().first;
                int col=q.front().second;q.pop();
                if(row==n-1&&col==n-1) return cnt;
                
                for(int k=0;k<8;k++){
                    int r=row+d[k][0];
                    int c=col+d[k][1];
                    if(r<0||c<0||r==n||c==n||grid[r][c]) continue;
                    grid[r][c]=1;
                    q.push({r,c});
                }
            }
            cnt++;
        }
        return -1;
        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        return bfs(n,grid);
    }
};