class Solution {
public:
    
    bool buddyStrings(string &s, string &goal) {
        int ns=s.length(),ng=goal.length();
        if(ns!=ng) return false;
        if(s==goal){
            vector<int> freq(26);
            for(int i=0;i<ns;i++){
                freq[s[i]-'a']++;
                if(freq[s[i]-'a']==2){
                    return true;
                }
            }
            return false;
        }
        
        int i=0,j=ns-1;
        
        while(i<j){
            
            while(s[i]==goal[i]){
                i++;
            }
            
            while(s[j]==goal[j]){
                j--;
            }
            if(i<j){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                if(s==goal){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }
};