class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            int start=0,end=n-1;
            int mid=start+(end-start)/2;
            int temp=0;
            while(start<=end){
                mid=start+(end-start)/2;
                if(grid[i][mid]<=-1){
                    end=mid-1;
                }
                else if(grid[i][mid]>-1){
                    start=mid+1;
                }
            }
            if(start>=0&&start<n){
                temp+=(n-1-start+1);
            }
            cnt+=temp;
            // cout<<temp<<endl;
        }
        return cnt;
    }
};