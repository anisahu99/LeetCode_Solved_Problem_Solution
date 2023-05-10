class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int up=0,left=0,down=n-1,right=n-1;
        int num=1;
        while(num<=n*n){
            for(int j=left;j<=right&&num<=n*n;j++){
                matrix[up][j]=num++;
            }
            for(int i=up+1;i<=down-1&&num<=n*n;i++){
                matrix[i][right]=num++;
            }
            for(int j=right;j>=left&&num<=n*n;j--){
                matrix[down][j]=num++;
            }
            for(int i=down-1;i>=up+1&&num<=n*n;i--){
                matrix[i][left]=num++;
            }
            up++;left++;right--;down--;
        }
        return matrix;
    }
};