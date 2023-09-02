class Solution {
public:
    vector<int> t;
    int solve(int idx,int &n,string &s,unordered_set<string>& dict){
        if(idx==n) return 0;
        if(t[idx]!=-1) return t[idx];
        
        int ans=n;
        
        string curr_string="";
        for(int i=idx;i<n;i++){
            curr_string.push_back(s[i]);
            
            int extra=dict.find(curr_string)==dict.end()?curr_string.length():0;
            ans=min(ans,extra+solve(i+1,n,s,dict));
        }
        return t[idx]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        for(string &str:dictionary){
            dict.insert(str);
        }
        int n=s.length();
        t.resize(n+1,-1);
        return solve(0,n,s,dict);
    }
};