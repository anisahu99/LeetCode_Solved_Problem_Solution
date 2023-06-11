class Solution {
public:
    void solve(int i,string ans,string s,vector<string> &res){
        
        if(i>=s.length()){
            //cout<<ans<<endl;
            res.push_back(ans);
            return;
        }
        
        if(s[i]>='a'&&s[i]<='z'){
            solve(i+1,ans+s[i],s,res);
            char ch=char(s[i]-32);
            solve(i+1,ans+ch,s,res);
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            solve(i+1,ans+s[i],s,res);
            char ch=char(s[i]+32);
            solve(i+1,ans+ch,s,res);
        }
        else
            solve(i+1,ans+s[i],s,res);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(0,"",s,res);
        return res;
    }
};