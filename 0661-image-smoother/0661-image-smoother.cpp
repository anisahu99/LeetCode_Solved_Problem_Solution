class Solution {
public:
//    (i-1,j-1)         (i-1,j)        (i-1,j+1)
    
//        (i,j-1)              (i,j)          (i,j+1)
    
//     (i+1,j-1)         (i+1,j)        (i+1,j+1)
    
    // myself
    
    vector<pair<int,int>> dir{{0,0},{-1,-1},{-1,0},{-1,+1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    void filter(int &row,int &col,int &m,int &n,vector<vector<int>>& img,vector<vector<int>>& ans){
        int total=0;
        int value=0;
        for(int k=0;k<9;k++){
            int n_r=row+dir[k].first;
            int n_c=col+dir[k].second;
            
            
            if(n_r>=0&&n_r<m&&n_c>=0&&n_c<n){
                if(img[n_r][n_c]){
                    value+=img[n_r][n_c];
                }
                total++;
            }
        }
        //cout<<"( "<<one<<"/"<<(one+zero)<<")"<<endl;
        ans[row][col]=value/total;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size(),n=img[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                filter(row,col,m,n,img,ans);
            }
        }
        return ans;
    }
};