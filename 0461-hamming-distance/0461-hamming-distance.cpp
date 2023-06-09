class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        for(int i=0;i<32;i++){
            int b1=x&(1<<i);
            int b2=y&(1<<i);
            if(b1^b2){
                ans++;
            }
        }
        return ans;
    }
};