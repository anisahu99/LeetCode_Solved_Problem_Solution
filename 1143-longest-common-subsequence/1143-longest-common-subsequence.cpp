class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,string &s1,string &s2,int &x,int &y){
        
        if(j>=y){
            return 0;
        }
        if(i>=x){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans1=0;
        int ans2=0;
        int ans3=0;
        if(s1[i]==s2[j]){
            ans1=1+solve(i+1,j+1,s1,s2,x,y);
        }
        else{
            ans2=0+solve(i,j+1,s1,s2,x,y);
            ans3=0+solve(i+1,j,s1,s2,x,y);
        }
        int ans=max(ans1,max(ans2,ans3));
        return dp[i][j]= ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int x=text1.length();
        int y=text2.length();
        dp.resize(x,vector<int>(y,-1));
        return solve(0,0,text1,text2,x,y);
    }
};