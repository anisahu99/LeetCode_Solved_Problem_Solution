class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &ch:s){
            if(ch=='('||ch=='['||ch=='{'){
                st.push(ch);
            }
            else if(ch==')'||ch==']'||ch=='}'){
                if(st.size()>0){
                    if(st.top()=='('&&ch==')'||st.top()=='['&&ch==']'||st.top()=='{'&&ch=='}')
                        st.pop();
                    else
                        return false;
                }
                else{
                    return false;
                }
            }
        }
        return st.size()>0?false:true;
    }
};