class Solution {
public:
    int solveTab(vector<int>& prices,int &fee){
        
        vector<int> curr(2,0);
        vector<int> next(2,0);
        
        
        for(int day=prices.size()-1;day>=0;day--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy){
                    //        sell call
                    int do_buy=next[0]-prices[day]-fee;

                    int not_buy=next[1];

                    profit=max(profit,max(do_buy,not_buy));
                }
                else{
                    //                       1 extra day for cool down
                    int sell=prices[day]+next[1];

                    int not_sell=next[0];

                    profit=max(profit,max(sell,not_sell));
                }

                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
        
    }
    int maxProfit(vector<int>& prices, int &fee) {
        return solveTab(prices,fee);
    }
};