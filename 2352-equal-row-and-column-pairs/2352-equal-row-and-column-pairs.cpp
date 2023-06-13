class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mp;
        int n=grid.size();
        for(int row=0;row<n;row++){
            string str;
            for(int col=0;col<n;col++){
                str+=to_string(grid[row][col])+"-";
            }
            mp[str]++;
        }
        int ans=0;
        for(int col=0;col<n;col++){
            string str;
            for(int row=0;row<n;row++){
                str+=to_string(grid[row][col])+"-";
            }
            if(mp.find(str)!=mp.end()){
                ans+=mp[str];
            }
        }
        return ans;
    }
};