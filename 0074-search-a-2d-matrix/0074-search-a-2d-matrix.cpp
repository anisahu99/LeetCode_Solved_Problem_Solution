class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int start=0,end=n-1;
        int i=0;
        while(i<m){
            //
            start=0,end=n-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                //cout<<matrix[i][mid]<<endl;
                if(matrix[i][mid]==target) return true;
                else if(matrix[i][mid]<target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            i++;
        }
        return false;
    }
};