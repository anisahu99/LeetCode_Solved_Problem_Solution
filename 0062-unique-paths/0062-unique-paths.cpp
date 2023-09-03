class Solution {
public:
    vector<vector<int>> t;
    int total_paths(int row,int col,int &m,int &n){
        if(row==m||col==n) return 0;
        if(row==m-1&&col==n-1) return 1;
        if(t[row][col]!=-1) return t[row][col];
        
        int right=total_paths(row,col+1,m,n);
        int down=total_paths(row+1,col,m,n);
        
        return t[row][col]=right+down;
    }
    int uniquePaths(int m, int n) {
        t.resize(m,vector<int>(n,-1));
        return total_paths(0,0,m,n);
    }
};