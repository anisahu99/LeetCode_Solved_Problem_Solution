class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int cnt=0;
        
        for(string &str:logs){
            if(str=="../"){
                if(cnt==0){
                    continue;
                }
                else
                    cnt--;
            }
            else if(str=="./"){
                continue;
            }
            else{
                cnt++;
            }
        }
        if(cnt<0)
            return 0;
        
        return cnt;
    }
};