class Solution {
public:
    typedef pair<int,int> P;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<P> temp;
        for(int row=0;row<m;row++){
            int cnt=0;
            for(int col=0;col<n;col++){
                if(mat[row][col]){
                    cnt++;
                }
            }
            temp.push_back({cnt,row});
        }
        sort(temp.begin(),temp.end());
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i]=temp[i].second;
        }
        return ans;
    }
};