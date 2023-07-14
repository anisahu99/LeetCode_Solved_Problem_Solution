class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int,int> mp;
        int ans=1;
        for(int &val:arr){
            if(mp.find(val-d)!=mp.end()){
                mp[val]=1+mp[val-d];
            }
            else{
                mp[val]=1;
            }
            ans=max(ans,mp[val]);
        }
        return ans;
    }
};