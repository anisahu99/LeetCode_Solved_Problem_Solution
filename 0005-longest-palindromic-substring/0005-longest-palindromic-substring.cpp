class Solution {
public:
    
    vector<vector<int>> dp;
    
    bool isPalin(int left,int right,string &s){
        if(left>=right)
            return true;
        
        if(dp[left][right]!=-1)
            return dp[left][right];
        
        if(s[left]!=s[right]){
            dp[left][right]=false;
            return false;
        }
        
        if(right-left<=2){
            dp[left][right]=true;
            return true;
        }
        
        
        return dp[left][right]=isPalin(left+1,right-1,s);
    }
    
    
    string longestPalindrome(string &s) {
        int len=s.length();
        int maxLen=0;
        int startingIndex=-1;
        dp.resize(len,vector<int>(len,-1));
        for(int left=0;left<len;left++){
            for(int right=left;right<len;right++){
                if(s[left]==s[right]&&isPalin(left+1,right-1,s)){
                    if(right-left+1>maxLen){
                        maxLen=right-left+1;
                        startingIndex=left;
                    }
                }
            }
        }
        return s.substr(startingIndex,maxLen);
    }
};