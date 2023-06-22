class Solution {
public:
    vector<vector<int>> dp;
    int solve(int day,bool buy,vector<int>& prices,int fee){
        if(day>=prices.size()){
            return 0;
        }
        if(dp[day][buy]!=-1){
            return dp[day][buy];
        }
        
        int profit=0;
        
        if(buy){
            //        sell call
            int do_buy=solve(day+1,false,prices,fee)-prices[day]-fee;
            
            int not_buy=solve(day+1,true,prices,fee);
            
            profit=max(profit,max(do_buy,not_buy));
        }
        else{
            //                       1 extra day for cool down
            int sell=prices[day]+solve(day+1,true,prices,fee);
            
            int not_sell=solve(day+1,false,prices,fee);
            
            profit=max(profit,max(sell,not_sell));
        }
        
        return dp[day][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return solve(0,true,prices,fee);
    }
};