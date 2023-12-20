class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1,min2;
        if(prices[0]>prices[1]){
            min2=prices[0];
            min1=prices[1];
        }
        else{
            min2=prices[1];
            min1=prices[0];
        }
        for(int i=2;i<prices.size();i++){
            if(min1>prices[i]){
                min2=min1;
                min1=prices[i];
            }
            else if(min2>prices[i]){
                min2=prices[i];
            }
        }
        if((min1+min2)<=money) return (money-(min1+min2));
        return money;
    }
};