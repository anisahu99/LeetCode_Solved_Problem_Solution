class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int i=0;
        int sum=0;
        while(i<m){
            sum+=mat[i][i];
            i++;
        }
        i=0;
        int j=m-1;
        while(i<m){
            if(i!=j)
                sum+=mat[i][j];
            i++;
            j--;
        }
        return sum;
    }
};