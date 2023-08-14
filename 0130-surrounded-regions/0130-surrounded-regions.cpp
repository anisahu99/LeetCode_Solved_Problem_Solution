class Solution {
public:
    vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    
    int m,n;
    
    
    void dfs(int row,int col,vector<vector<char>>& board){
        if(row<0||row==m||col<0||col==n||board[row][col]=='X'||board[row][col]=='#') return;
        
        board[row][col]='#';
        
        for(int k=0;k<4;k++){
            dfs(row+dir[k].first,col+dir[k].second,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        m=board.size(),n=board[0].size();
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0||row==m-1||col==0||col==n-1&&board[row][col]=='O'){
                    dfs(row,col,board);
                }
            }
        }
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='O'){
                    board[row][col]='X';
                }
            }
        }
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='#'){
                    board[row][col]='O';
                }
            }
        }
    }
};