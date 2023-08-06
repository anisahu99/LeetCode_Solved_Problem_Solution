class Solution {
public:
    vector<vector<int>> t;
    int solve(int n,int turn){
        if(n==0&&turn){
            return 0;
        }
        if(n==0&&turn==0){
            return 1;
        }
        if(t[n][turn]!=-1) return t[n][turn];
        if(turn){
            for(int x=1;x<n;x++){
                if(n%x==0){
                    int temp=solve(n-x,0);
                    if(temp) return t[n][turn]=1;
                }
            }
            return t[n][turn]=0;
        }
        else{
            for(int x=1;x<n;x++){
                if(n%x==0){
                    int temp=solve(n-x,1);
                    if(temp==0) return t[n][turn]=0;
                }
            }
            return t[n][turn]=1;
        }
        return t[n][turn]=0;
    }
    bool divisorGame(int n) {
        t.resize(n+1,vector<int>(2,-1));
        return solve(n,1);
    }
};