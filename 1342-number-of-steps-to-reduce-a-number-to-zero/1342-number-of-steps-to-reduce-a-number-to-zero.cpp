class Solution {
public:
    int numberOfSteps(int num) {
        if(!num) return 0;
        int cnt=0;
        while(num!=0){
            if(num%2==0){
                num=num/2;
            }
            else{
                num=num-1;
            }
            cnt++;
        }
        return cnt;
    }
};