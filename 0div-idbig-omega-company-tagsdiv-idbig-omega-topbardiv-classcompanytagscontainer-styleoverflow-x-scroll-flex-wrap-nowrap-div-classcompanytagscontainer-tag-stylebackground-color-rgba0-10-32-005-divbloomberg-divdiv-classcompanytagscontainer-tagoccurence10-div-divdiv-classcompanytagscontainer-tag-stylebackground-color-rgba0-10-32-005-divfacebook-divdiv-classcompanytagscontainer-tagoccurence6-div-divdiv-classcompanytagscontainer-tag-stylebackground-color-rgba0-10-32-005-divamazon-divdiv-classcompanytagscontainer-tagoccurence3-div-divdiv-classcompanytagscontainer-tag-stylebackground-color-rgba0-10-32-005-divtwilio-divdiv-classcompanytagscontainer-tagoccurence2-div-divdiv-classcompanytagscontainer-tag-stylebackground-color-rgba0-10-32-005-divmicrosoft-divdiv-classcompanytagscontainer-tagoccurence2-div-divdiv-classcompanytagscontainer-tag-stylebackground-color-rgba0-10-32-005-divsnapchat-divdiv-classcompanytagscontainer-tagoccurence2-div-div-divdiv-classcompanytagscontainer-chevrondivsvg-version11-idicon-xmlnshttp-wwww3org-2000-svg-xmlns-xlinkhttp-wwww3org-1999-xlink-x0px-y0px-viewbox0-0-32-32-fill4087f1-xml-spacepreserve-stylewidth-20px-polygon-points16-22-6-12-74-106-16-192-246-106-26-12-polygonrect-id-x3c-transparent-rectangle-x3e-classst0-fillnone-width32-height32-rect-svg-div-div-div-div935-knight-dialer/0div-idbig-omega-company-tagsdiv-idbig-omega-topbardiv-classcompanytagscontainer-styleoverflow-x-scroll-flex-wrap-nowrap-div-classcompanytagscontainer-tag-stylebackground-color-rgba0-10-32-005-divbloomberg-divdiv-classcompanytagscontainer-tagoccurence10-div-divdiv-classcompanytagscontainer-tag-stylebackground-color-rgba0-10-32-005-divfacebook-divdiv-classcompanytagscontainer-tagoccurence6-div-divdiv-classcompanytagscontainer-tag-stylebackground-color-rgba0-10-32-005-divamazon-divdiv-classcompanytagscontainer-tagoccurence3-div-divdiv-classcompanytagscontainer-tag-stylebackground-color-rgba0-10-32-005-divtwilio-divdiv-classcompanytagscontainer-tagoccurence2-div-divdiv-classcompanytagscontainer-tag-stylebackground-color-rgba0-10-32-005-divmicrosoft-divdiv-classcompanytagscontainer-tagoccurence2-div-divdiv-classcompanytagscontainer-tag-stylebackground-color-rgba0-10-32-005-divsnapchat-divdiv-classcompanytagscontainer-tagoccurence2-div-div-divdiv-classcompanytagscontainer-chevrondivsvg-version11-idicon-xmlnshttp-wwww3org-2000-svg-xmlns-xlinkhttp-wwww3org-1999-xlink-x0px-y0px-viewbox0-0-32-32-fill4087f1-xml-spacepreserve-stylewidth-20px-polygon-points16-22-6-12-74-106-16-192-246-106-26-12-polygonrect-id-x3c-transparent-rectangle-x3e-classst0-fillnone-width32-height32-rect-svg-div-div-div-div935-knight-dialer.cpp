class Solution {
public:
    int mod=1e9+7;
    vector<pair<int,int>> dir{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    
    int t[4][3][5001];
    
    int solve(int row,int col,int n){
        if(row<0||row>=4||col<0||col>=3) return 0;
        if(row==3&&(col==0||col==2)) return 0;
        
        if(n==0&&row>=0&&row<4&&col>=0&&col<3&&!(row==3&&(col==0||col==2))){
            return 1;  
        } 
        
        if(t[row][col][n]!=-1) return t[row][col][n];
        
        
        int ans=0;
        
        for(int t=0;t<8;t++){
            ans=(ans+solve(row+dir[t].first,col+dir[t].second,n-1)%mod)%mod;
        }
        return t[row][col][n]=ans;
    }
    
    int knightDialer(int n) {
        memset(t,-1,sizeof(t));
        int ans=0;
        for(int row=0;row<4;row++){
            for(int col=0;col<3;col++){
                if(row==3&&(col==0||col==2)) continue;
                ans=(ans+solve(row,col,n-1)%mod)%mod;
            }
        }
        return ans;
    }
};