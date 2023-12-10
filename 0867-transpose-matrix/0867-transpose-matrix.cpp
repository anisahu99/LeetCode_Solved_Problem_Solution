class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int col=0;col<n;col++){
            vector<int> res;
            for(int row=0;row<m;row++){
                res.push_back(matrix[row][col]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};