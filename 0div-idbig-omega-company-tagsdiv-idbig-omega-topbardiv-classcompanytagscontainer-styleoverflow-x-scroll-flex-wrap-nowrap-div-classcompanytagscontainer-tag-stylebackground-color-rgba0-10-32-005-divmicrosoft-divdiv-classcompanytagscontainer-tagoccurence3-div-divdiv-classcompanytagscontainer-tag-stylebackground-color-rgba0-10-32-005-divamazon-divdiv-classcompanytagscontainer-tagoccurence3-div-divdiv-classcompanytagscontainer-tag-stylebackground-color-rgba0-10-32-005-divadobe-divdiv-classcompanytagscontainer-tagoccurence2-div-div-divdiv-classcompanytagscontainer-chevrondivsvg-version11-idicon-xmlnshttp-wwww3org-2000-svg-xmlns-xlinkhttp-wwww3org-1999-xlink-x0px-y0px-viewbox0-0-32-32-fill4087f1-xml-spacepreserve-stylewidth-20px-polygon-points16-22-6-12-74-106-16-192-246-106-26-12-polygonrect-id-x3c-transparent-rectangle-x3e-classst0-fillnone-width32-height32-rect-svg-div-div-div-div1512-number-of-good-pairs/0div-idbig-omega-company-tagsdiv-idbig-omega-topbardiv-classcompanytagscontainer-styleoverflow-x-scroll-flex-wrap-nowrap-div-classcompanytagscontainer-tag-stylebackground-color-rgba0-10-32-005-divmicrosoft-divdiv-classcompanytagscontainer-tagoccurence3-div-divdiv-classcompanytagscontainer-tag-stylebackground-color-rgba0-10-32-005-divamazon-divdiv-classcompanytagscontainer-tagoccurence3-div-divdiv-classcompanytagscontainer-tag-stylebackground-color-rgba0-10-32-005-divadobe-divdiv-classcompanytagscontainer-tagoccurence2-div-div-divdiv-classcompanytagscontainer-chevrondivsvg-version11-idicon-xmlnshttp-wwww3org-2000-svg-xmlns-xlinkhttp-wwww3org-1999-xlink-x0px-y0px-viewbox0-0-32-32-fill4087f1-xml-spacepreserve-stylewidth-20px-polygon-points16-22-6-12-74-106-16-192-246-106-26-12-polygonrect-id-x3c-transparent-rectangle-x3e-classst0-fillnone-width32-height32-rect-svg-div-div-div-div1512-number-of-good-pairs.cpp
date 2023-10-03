class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int good=0;
        for(int &num:nums){
            good+=mp[num];
            mp[num]++;
        }
        return good;
    }
};