class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int num=0;
        for(char ch:allowed){
            num=(num|(1<<(ch-'a')));
        }
        int cnt=0;
        for(int i=0;i<words.size();i++){
            int x=0;
            bool flag=true;
            for(char ch:words[i]){
                if(!(num&(1<<(ch-'a')))){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cnt++;
            }
        }
        return cnt;
    }
};