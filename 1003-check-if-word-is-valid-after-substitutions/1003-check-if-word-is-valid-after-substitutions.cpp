class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(n<3) return false;
        //if(n==3&&s=="abc") return true;
        
        stack<char> st;
        int i=0;
        while(i<n){
            if(i+2<n&&s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c'){
                i=i+3;
            }
            else{
                st.push(s[i]);
                i=i+1;
            }
        }
        if(st.empty())
            return true;
        while(st.size()>3){
            s="";
            while(!st.empty()){
                s.push_back(st.top());
                st.pop();
            }
            reverse(s.begin(),s.end());
            //
            int i=0;
            n=s.length();
            bool flag=false;
            while(i<n){
                if(i+2<n&&s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c'){
                    i=i+3;
                    flag=true;
                }
                else{
                    st.push(s[i]);
                    i=i+1;
                }
            }
            if(!flag)
                return false;
        }
        s="";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        if(s=="cba"||s=="")
            return true;
        return false;
    }
};