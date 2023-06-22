class Solution {
public:
    int solveTab(int &x, int &y, string &s1, string &s2){
        
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        for(int i=x-1;i>=0;i--){
            for(int j=y-1;j>=0;j--){
                int ans1=0;
                int ans2=0;
                int ans3=0;
                if(s1[i]==s2[j]){
                    ans1=1+dp[i+1][j+1];
                }
                else{
                    ans2=0+dp[i][j+1];
                    ans3=0+dp[i+1][j];
                }
                int ans=max(ans1,max(ans2,ans3));
                dp[i][j]= ans;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int x=text1.length();
        int y=text2.length();
        
        return solveTab(x,y,text1,text2);

    }
};