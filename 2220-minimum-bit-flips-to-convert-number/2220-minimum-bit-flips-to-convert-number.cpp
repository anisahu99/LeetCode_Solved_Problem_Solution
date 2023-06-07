class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        for(int i=0;i<32;i++){
            int b1=(start&(1<<i));
            int b2=(goal&(1<<i));
            if(b1!=b2)
                cnt++;
        }
        return cnt;
    }
};