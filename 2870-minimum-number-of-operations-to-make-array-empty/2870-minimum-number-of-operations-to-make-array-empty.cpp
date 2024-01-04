class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int &num:nums){
            freq[num]++;
        }
        int cnt=0;
        for(auto it:freq){
            if(it.second==1) return -1;
            else if(it.second%3==0) cnt+=it.second/3;
            else{
                cnt+=it.second/3+1;
            }
        }
        return cnt;
    }
};