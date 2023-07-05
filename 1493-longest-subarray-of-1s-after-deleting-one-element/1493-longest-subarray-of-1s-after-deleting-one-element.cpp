class Solution {
public:
    
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int i=0,n=nums.size();
        int cnt=0;
        int extra=0;
        bool getZeroOrNot=false;
        while(i<n){
            if(nums[i]==0){
                ans=max(ans,cnt);
                ans=max(ans,extra);
                extra=cnt;
                cnt=0;
                getZeroOrNot=true;
            }
            else{
                cnt++;
                extra++;
            }
            i++;
        }
        ans=max(ans,max(extra,cnt));
        
        return getZeroOrNot==true?ans:ans-1;
    }
};