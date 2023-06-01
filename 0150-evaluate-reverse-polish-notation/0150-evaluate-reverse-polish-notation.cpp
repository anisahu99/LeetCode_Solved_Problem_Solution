class Solution {
public:
    bool isOperator(string str){
        if(str=="+"||str=="-"||str=="*"||str=="/")
            return true;
        return false;
    }
    int eval(int x1,int x2,string str){
        if(str=="+")
            return (x1+x2);
        else if(str=="-")
            return (x1-x2);
        else if(str=="*")
            return (x1*x2);
        else if(str=="/")
            return (x1/x2);
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string str:tokens){
            if(isOperator(str)){
                int x2=st.top();st.pop();
                int x1=st.top();st.pop();
                
                st.push(eval(x1,x2,str));
            }
            else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};