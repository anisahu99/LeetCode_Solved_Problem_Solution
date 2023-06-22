class Solution {
public:
    int solveTab(vector<int>& prices,int &fee){
        vector<vector<int>> dp(prices.size()+1,vector<int>(3,0));
        
        
        for(int day=prices.size()-1;day>=0;day--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy){
                    //        sell call
                    int do_buy=dp[day+1][0]-prices[day]-fee;

                    int not_buy=dp[day+1][1];

                    profit=max(profit,max(do_buy,not_buy));
                }
                else{
                    //                       1 extra day for cool down
                    int sell=prices[day]+dp[day+1][1];

                    int not_sell=dp[day+1][0];

                    profit=max(profit,max(sell,not_sell));
                }

                dp[day][buy]=profit;
            }
        }
        return dp[0][1];
        
    }
    int maxProfit(vector<int>& prices, int &fee) {
        return solveTab(prices,fee);
    }
};