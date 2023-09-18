class Solution {
public:
    //Explanation By Aryan Mittal Youtuber in the last 10 min of video
    //https://www.youtube.com/watch?v=Qt_gbCWqFdY&t=30s
    //Optimal Approach
    
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int &num:nums){
            freq[num]++;
        }
        int mx=0;
        for(auto it:freq){
            mx=max(it.second,mx);
        }
        if(2*mx<=n) return n&1?1:0;
        else
            return n-2*(n-mx);
    }
};