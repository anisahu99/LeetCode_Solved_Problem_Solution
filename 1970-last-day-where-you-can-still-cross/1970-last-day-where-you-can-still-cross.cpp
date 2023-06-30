class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool canReach(int row,int col,int &m,int &n,vector<vector<int>> &mat){
        if(row<0||row==m||col<0||col==n||mat[row][col]||mat[row][col]==-1){
            return false;
        }
        if(row==m-1){
            return true;
        }
        
        int temp=mat[row][col];
        mat[row][col]=1;//mark as visited 
        bool ans=false;
        for(int k=0;k<4;k++){
            ans=canReach(row+x[k],col+y[k],m,n,mat);
            if(ans){
                break;
            }
        }
        //we unmark but ham nhi krenge iski jaroort nhi hai agr kr dia to TLE maar dega.
        return ans;
        
    }
    //
    bool canCross(vector<vector<int>>& cells, int mid,int &m,int &n) {
        vector<vector<int>> mat(m, vector<int>(n));
        
        for (int i = 0; i <= mid; ++i) {
            mat[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        
        for (int col = 0; col < n; col++) {
            if (mat[0][col] == 0 &&canReach(0,col,m,n,mat)) {
                return true;
            }
        }
        return false;
    }
    //
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        int ans=0;
        int start=0,end=cells.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(canCross(cells,mid,m,n)){
                ans=mid+1;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};