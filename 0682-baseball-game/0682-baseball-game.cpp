class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        bool flag=false;
        for(string &str:operations){
            if(str=="+"||str=="D"||str=="C"){
                if(str=="D"){
                    st.push(2*st.top());
                }
                else if(str=="C"&&st.size()){
                    st.pop();
                }else{
                    if(st.size()>1){
                        int x1=st.top();st.pop();
                        int x2=st.top();
                        st.push(x1);
                        st.push(x1+x2);
                    }
                }
            }else{
                st.push(stoi(str));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};