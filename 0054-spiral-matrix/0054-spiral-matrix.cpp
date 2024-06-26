class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return {};
        vector<int> res;
        int m=matrix.size(),n=matrix[0].size();
        int up=0,down=m-1,left=0,right=n-1;
        while(res.size()<m*n){
            for(int j=left;j<=right&&res.size()<m*n;j++){
                res.push_back(matrix[up][j]);
            }
            for(int i=up+1;i<=down-1&&res.size()<m*n;i++){
                res.push_back(matrix[i][right]);
            }
            for(int j=right;j>=left&&res.size()<m*n;j--){
                res.push_back(matrix[down][j]);
            }
            for(int i=down-1;i>=up+1&&res.size()<m*n;i--){
                res.push_back(matrix[i][left]);
            }
            left++;up++;right--;down--;
        }
        return res;
    }
};