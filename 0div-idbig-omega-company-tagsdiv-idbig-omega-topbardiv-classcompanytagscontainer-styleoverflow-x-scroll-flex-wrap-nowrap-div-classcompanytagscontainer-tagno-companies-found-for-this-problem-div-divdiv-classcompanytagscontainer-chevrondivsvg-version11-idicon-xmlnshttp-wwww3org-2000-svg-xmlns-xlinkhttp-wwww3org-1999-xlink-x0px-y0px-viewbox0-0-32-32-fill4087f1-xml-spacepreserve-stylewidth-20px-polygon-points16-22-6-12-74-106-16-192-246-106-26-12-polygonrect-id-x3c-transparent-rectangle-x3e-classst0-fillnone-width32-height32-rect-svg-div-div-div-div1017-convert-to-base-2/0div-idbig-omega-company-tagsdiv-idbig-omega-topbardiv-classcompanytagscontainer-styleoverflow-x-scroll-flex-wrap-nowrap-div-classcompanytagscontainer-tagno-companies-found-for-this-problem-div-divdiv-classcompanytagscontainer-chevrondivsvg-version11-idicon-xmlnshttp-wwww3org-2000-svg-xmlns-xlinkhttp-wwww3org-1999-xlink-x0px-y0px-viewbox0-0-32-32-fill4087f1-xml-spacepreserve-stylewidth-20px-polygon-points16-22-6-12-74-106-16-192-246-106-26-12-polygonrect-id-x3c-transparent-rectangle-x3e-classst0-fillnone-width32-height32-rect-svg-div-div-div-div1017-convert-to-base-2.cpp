class Solution {
public:
    //https://leetcode.com/problems/convert-to-base-2/discuss/2082966/C%2B%2B-or-Easy-solution-with-detailed-explanation
    string baseNeg2(int n) {
        string ans="";
        if(n==0)
            ans+=('0');
        int r;
        while(n){
            r=n%(-2);
            if(r<0){
                r+=2;
                n=n/(-2)+1;
            }else
                n/=(-2);
            ans+=(r+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};