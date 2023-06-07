class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2,0);
        for(int i=0;i<32;i++){
            int b=(n&(1<<i));
            if(b){
                if(i%2==0){
                    ans[0]++;
                }
                else{
                    ans[1]++;
                }
            }
        }
        return ans;
    }
};