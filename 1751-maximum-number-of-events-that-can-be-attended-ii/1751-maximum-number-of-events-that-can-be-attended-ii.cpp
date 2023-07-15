class compare {
public:
    // Comparator function
    bool operator()(const vector<int> &v1, const vector<int> &v2)
    {
        if(v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        return v1[0]<v2[0];
    }
};

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int k,vector<vector<int>>& events){
        if(k==0){
            return 0;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        
        int result=0;
        for(int j=i+1;j<n;j++){
            if(events[i][1]<events[j][0]){
                result=max(result,solve(j,k-1,events));
                break;
            }
        }
        result+=events[i][2];
        int not_take=solve(i+1,k,events);
        
        return dp[i][k]=max(result,not_take);
    }
//     void solve(int i,int k,vector<vector<int>>& events,string ans){
//         if(k==0){
//             cout<<ans<<endl;
//             return;
//         }
//         if(i==n){
//             cout<<ans<<endl;
//             return;
//         }
        
//         for(int j=i+1;j<n;j++){
//             if(events[i][1]<events[j][0]){
//                 solve(j,k-1,events,ans+to_string(events[i][2])+"-");
//             }
//         }
//         solve(i+1,k,events,ans);
        
//     }

    int maxValue(vector<vector<int>>& events, int k) {
        compare cmp;
        n=events.size();
        sort(events.begin(),events.end(),cmp);
        dp.resize(n,vector<int>(k+1,-1));
        return solve(0,k,events);
        // solve(0,k,events,"");
        // return 0;
        
    }
};