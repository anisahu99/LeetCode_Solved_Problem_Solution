class Solution {
public:
    //brute force
    // O(n^3)
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                int cnt=0;
                for(int i=0;i<n;i++){
                    if(grid[row][i]!=grid[i][col]){
                        break;
                    }
                    else{
                        cnt++;
                    }
                }
                if(cnt==n){
                    ans++;
                }
            }   
        }
        return ans;
        
    }
};