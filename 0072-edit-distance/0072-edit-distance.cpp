class Solution {
public:
    int solveTab(string &s1,string &s2,int x,int y){
        
        vector<int> curr(y+1,0);
        vector<int> next(y+1,0);
        
        for(int j=0;j<y;j++){
            next[j]=y-j;
        }
        
        for(int i=x-1;i>=0;i--){
            for(int j=y-1;j>=0;j--){
                curr[y]=x-i;
                int ans=0;
                if(s1[i]==s2[j]){
                    curr[j]=next[j+1];
                }
                else{
                    int insrt=1+curr[j+1];
                    int rplc=1+next[j+1];
                    int delt=1+next[j];
                    
                    ans=min(insrt,min(rplc,delt));
                    curr[j]=ans;
                }
            }
            next=curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        if(word1.length()==0)
            return word2.length();
        if(word2.length()==0)
            return word1.length();
        
        return solveTab(word1,word2,word1.length(),word2.length());
    }
};