class Solution {
public:
    
    bool isPred(string &s1,string &s2){
        
        int i=0,j=0;
        bool flag=true;
        while(i<s1.length()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else if(flag){
                j++;
                flag=false;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    
    
    int solve(int i,int prev,vector<string> &words,vector<vector<int>> &dp){
        if(i==words.size()) return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int take=0;
        
        if(prev==-1||words[i].length()==words[prev].length()+1&&isPred(words[prev],words[i])){
            take=1+solve(i+1,i,words,dp);
        }
        int not_take=0+solve(i+1,prev,words,dp);
        
        return dp[i][prev+1]=max(take,not_take);
    }
    static bool comp(string &s1,string &s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,words,dp);
    }
};