class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        int curr=0;
        while(mp.find(curr)!=mp.end()){
            for(int val:mp[curr]){
                ans.push_back(val);
            }
            curr++;
        }
        return ans;
    }
};