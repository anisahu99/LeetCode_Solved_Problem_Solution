class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0;i<32;i++){
            int b1=(a&(1<<i));
            int b2=(b&(1<<i));
            int b3=(c&(1<<i));
            //cout<<b1<<":"<<b2<<":"<<b3<<endl;
            if(b3){
                if(!b1&&!b2){//if both bit is off
                    cnt++;
                }
            }
            else{
                if(b1&&!b2){
                    cnt++;
                }
                else if(!b1&&b2){
                    cnt++;
                }
                else if(b1&&b2){
                    cnt=cnt+2;
                }
            }
        }
        return cnt;
    }
};