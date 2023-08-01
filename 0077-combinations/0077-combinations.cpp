class Solution {
public:
    vector<vector<int>> solve(int n,int k,int i){
        if(k==0){
            vector<vector<int>> t;
            return {{}};
        }
        vector<vector<int>> res;
        for(int j=i;j<=n;j++){
            vector<vector<int>> v=solve(n,k-1,j+1);
            for(vector<int>& a:v){
                    vector<int> temp;
                    temp.push_back(j);
                    for(int &val:a){
                        temp.push_back(val);
                    }
                    res.push_back(temp);
                }   
        }
        return res;
    }
    vector<vector<int>> combine(int n, int k) {
        return solve(n,k,1);
    }
};