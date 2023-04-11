class Solution {
public:
    string removeStars(string &s) {
        stack<char> st;
        for(char &ch:s){
            if(ch!='*'){
                st.push(ch);
            }
            else{
                if(st.size()>0){
                    st.pop();
                }
            }
        }
        if(st.size()==0) return "";
        s.clear();
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};