class Solution {
public:
    int totalMoney(int n) {
        
        int money=0;
        int counter=1;
        while(n>7){
            money+=((7)*(2*counter+6))/2;
            n-=7;
            counter++;
        }
        money+=((n)*(2*counter+(n-1)))/2;
        return money;
    }
};