class Solution {
public:
    int solve(string &s,int idx){
        //cout<<idx<<endl;
        if(s.length()==1||idx==s.length()-1){
            return 1;
        }
        int cnt=1;
        unordered_set<char> st;
        for(int i=idx;i<s.length();i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
            }
            else{
                cnt+=solve(s,i);
                break;
            }
        }
        return cnt;
    }
    int partitionString(string &s) {
        return solve(s,0);
    }
};