class Solution {
public:
    int addDigits(int& num) {
        
        while(num/10!=0){
            int s=0;
            while(num){
                s+=num%10;
                num=num/10;
            }
            num=s;
        }
        return num;
    }
};