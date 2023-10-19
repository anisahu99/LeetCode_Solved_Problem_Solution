class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sans="";
        string tans="";
        int i=0;
            while(s[i]!='\0'){
                    if(s[i]>='a'&&s[i]&&s[i]<='z'){
                            sans+=s[i];
                    }
                    else if(!sans.empty()){
                            sans.pop_back();
                    }
                    i++;
            }
            i=0;
            while(t[i]!='\0'){
                    if(t[i]>='a'&&t[i]&&t[i]<='z'){
                            tans+=t[i];
                    }
                    else if(!tans.empty()){
                            tans.pop_back();
                    }
                    i++;
            }
            if(sans.compare(tans)==0)
                    return true;
            return false;
    }
};