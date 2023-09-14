//     //https://www.youtube.com/watch?v=CsK02Hi796U
//     //Digit DP

#define ll long long
class Solution {
public:
    int mod=1e9+7;
    int dp[101][2][2][11];
    int countStrings(int ind,bool tight, bool leading, string &num, int prev=-1){
        if(ind==num.size())return 1;

        if(dp[ind][tight][leading][prev+1]!=-1)return dp[ind][tight][leading][prev+1];

        ll hi=tight?num[ind]-'0':9;

        ll count =0;
        for(int i=0;i<=hi;i++){
            if(prev!=-1 && !leading){
                if(abs(prev-i)==1)count=(count + countStrings(ind+1,tight&(i==hi),leading&(i==0), num, i))%mod;

                continue;
            }
            count=(count + countStrings(ind+1,tight&(i==hi),leading&(i==0), num, i))%mod;
        }

        return dp[ind][tight][leading][prev+1]=count;
    }

    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));


        ll a=countStrings(0,1,1,low);

        int valid=1;
        for(int i=1;i<low.size();i++){
            if(abs(low[i]-low[i-1])!=1){
                valid=0;
                break;
            }
        }

        a-=valid;
        memset(dp,-1,sizeof(dp));

        ll b=countStrings(0,1,1,high);

        return (b-a+mod)%mod;
    }
};