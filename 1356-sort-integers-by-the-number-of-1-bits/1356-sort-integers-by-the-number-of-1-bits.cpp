class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>> mp;
        sort(arr.begin(),arr.end());
        for(int num:arr){
            int cnt=0;
            for(int i=0;i<32;i++){
                if(num&(1<<i)){
                    cnt++;
                }
            }
            mp[cnt].push_back(num);
        }
        vector<int> ans;
        for(auto it:mp){
            vector<int> v=it.second;
            for(int val:v){
                ans.push_back(val);
            }
        }
        return ans;
    }
};