class Solution {
public:

    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        //slight optimization
        for(int l=n/2;l>=1;l--){
            string piece=s.substr(0,l);
            if(l>(n-l)) continue;
            int i=0;
            bool flag=true;
            while(i<n){
                if(s[i]==piece[i%l]){
                    i++;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag&&i%l==0){
                //cout<<l<<endl;
                return true;
            }
        }
        return false;
    }
};