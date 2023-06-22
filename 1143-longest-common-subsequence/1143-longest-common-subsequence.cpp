class Solution {
public:
    int solveOptimal(int &x, int &y, string &s1, string &s2){
        

        vector<int> curr1(y+1,0);

        vector<int> next1(y+1,0);
        
        for(int i=x-1;i>=0;i--){
            for(int j=y-1;j>=0;j--){
                int ans1=0;
                int ans2=0;
                int ans3=0;
                if(s1[i]==s2[j]){
                    ans1=1+next1[j+1];
                }
                else{
                    ans2=0+curr1[j+1];
                    ans3=0+next1[j];
                }
                int ans=max(ans1,max(ans2,ans3));
                curr1[j]= ans;
            }
            next1=curr1;
        }
        return next1[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int x=text1.length();
        int y=text2.length();
        
        return solveOptimal(x,y,text1,text2);

    }
};