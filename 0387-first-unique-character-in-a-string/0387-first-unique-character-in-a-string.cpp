class Solution {
public:
    int firstUniqChar(string s) {
        int frequency[26];
            int n=s.length();
            memset(frequency,0,sizeof(frequency));
            for(int i=0;i<n;i++){
                    frequency[s[i]-'a']++;
            }
            for(int i=0;i<n;i++){
                    if(frequency[s[i]-'a']==1){
                            return i;
                    }
            }
            return -1;
    }
};