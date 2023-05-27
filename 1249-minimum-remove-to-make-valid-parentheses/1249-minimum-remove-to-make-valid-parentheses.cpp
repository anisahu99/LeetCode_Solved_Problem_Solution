class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }else if(!st.empty()&&s[i]==')'&&st.top().first=='('){
                st.pop();
            }
            else if(s[i]==')'){
                st.push({s[i],i});
            }
        }
        unordered_set<int> index;
        while(!st.empty()){
            index.insert(st.top().second);
            st.pop();
        }
        string ans;
        for(int i=0;i<s.length();i++){
            if(index.find(i)==index.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};