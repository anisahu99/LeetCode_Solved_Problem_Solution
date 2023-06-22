class Solution {
public:
    int solveTab(vector<int>& prices,int &fee){
        
        int curr0=0;
        int curr1=0;
        int next0=0;
        int next1=0;
        
        vector<int> curr(2,0);
        vector<int> next(2,0);
        
        
        for(int day=prices.size()-1;day>=0;day--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy){
                    //        sell call
                    int do_buy=next0-prices[day]-fee;

                    int not_buy=next1;

                    profit=max(profit,max(do_buy,not_buy));
                }
                else{
                    //                       1 extra day for cool down
                    int sell=prices[day]+next1;

                    int not_sell=next0;

                    profit=max(profit,max(sell,not_sell));
                }
                
                if(buy==1){
                    curr1=profit;
                }else{
                    curr0=profit;
                }

            }
            next0=curr0;
            next1=curr1;
        }
        return next1;
        
    }
    int maxProfit(vector<int>& prices, int &fee) {
        return solveTab(prices,fee);
    }
};