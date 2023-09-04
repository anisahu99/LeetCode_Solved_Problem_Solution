//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int row,int col,int &m,int &n,vector<vector<char>>& board,vector<pair<int,int>> &dir){
        if(row<0||row==m||col<0||col==n||board[row][col]=='X'||board[row][col]=='#') return;
        
        board[row][col]='#';
        
        for(int k=0;k<4;k++){
            dfs(row+dir[k].first,col+dir[k].second,m,n,board,dir);
        }
    }
    vector<vector<char>> fill(int &m, int &n, vector<vector<char>>& board)
    {
        // code here
        vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0||row==m-1||col==0||col==n-1&&board[row][col]=='O'){
                    dfs(row,col,m,n,board,dir);
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
        return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends