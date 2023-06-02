class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<pair<int,int>> v(n,{0,0});
        int ca=0,cb=0;
        for(int i=0;i<n;i++){
            v[i].second=cb;
            v[n-1-i].first=ca;
            if(s[i]=='b'){
                cb++;
            }
            if(s[n-1-i]=='a'){
                ca++;
            }
        }
        int ans=INT_MAX;
        for(auto it:v){
            ans=min(ans,it.first+it.second);
        }
        return ans;
    }
};