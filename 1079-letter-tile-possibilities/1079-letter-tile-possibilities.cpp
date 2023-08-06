class Solution {
public:
    void solve(int n,vector<int>& vis,string &tiles,string ans,unordered_set<string>& duplicacy){
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                //cout<<ans+tiles[i]<<" ,";
                duplicacy.insert(ans+tiles[i]);
                solve(n,vis,tiles,ans+tiles[i],duplicacy);
                vis[i]=0;
            }
        }
    }
    int numTilePossibilities(string &tiles) {
        int n=tiles.length();
        vector<int> vis(n);
        unordered_set<string> duplicacy;
        solve(n,vis,tiles,"",duplicacy);
        return duplicacy.size();
    }
};