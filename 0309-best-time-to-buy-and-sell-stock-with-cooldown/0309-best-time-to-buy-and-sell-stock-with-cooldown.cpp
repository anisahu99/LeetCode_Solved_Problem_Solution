class Solution {
public:
    vector<vector<int>> dp;
    int solve(int day,bool buy,vector<int>& prices){
        if(day>=prices.size()){
            return 0;
        }
        if(dp[day][buy]!=-1){
            return dp[day][buy];
        }
        
        int profit=0;
        
        if(buy){
            //        sell call
            int do_buy=solve(day+1,false,prices)-prices[day];
            
            int not_buy=solve(day+1,true,prices);
            
            profit=max(profit,max(do_buy,not_buy));
        }
        else{
            //                       1 extra day for cool down
            int sell=prices[day]+solve(day+2,true,prices);
            
            int not_sell=solve(day+1,false,prices);
            
            profit=max(profit,max(sell,not_sell));
        }
        
        return dp[day][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return solve(0,true,prices);
    }
};