class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
            for(int i=0;i<s.length();i++){
                    m[s[i]]++;
            }
            for(int i=0;i<t.length();i++){
                    char ch=t[i];
                    if(m.find(ch)==m.end())
                            return false;
                    else if(m.find(ch)!=m.end()){
                            if(m[ch]==1){
                                    m.erase(ch);
                            }
                            else{
                                    m[ch]--;
                            }
                    }
            }
            if(m.size()==0)
                    return true;
            return false;
    }
};