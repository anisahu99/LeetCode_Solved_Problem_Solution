class Solution {
public:
    int numberOfMatches(int n) {
        if(n==1) return 0;
        int totalMatch=0;
        
        while(n>1){
            if(n&1){
                totalMatch+=(n-1)/2;
                n=(n-1)/2 + 1;
            }
            else{
                totalMatch+=n/2;
                n=n/2;
            }
        }
        return totalMatch;
    }
};