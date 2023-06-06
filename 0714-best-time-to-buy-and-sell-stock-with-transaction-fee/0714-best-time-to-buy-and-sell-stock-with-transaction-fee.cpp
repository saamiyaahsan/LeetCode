class Solution {
public:
    
    int helper(vector<int>& prices,int ind,int buy,int fee,vector<vector<int>>& dp)
    {
        if(ind == prices.size())
        {
            return 0;
        }
        
        if(dp[ind][buy] != -1)
        {
            return dp[ind][buy];
        }
        
        int profit = 0;
        
        if(buy == 1)
        {
            profit = max(helper(prices,ind+1,1,fee,dp),-prices[ind]+helper(prices,ind+1,0,fee,dp));
        }
        
        else
        {
             profit = max(helper(prices,ind+1,0,fee,dp),prices[ind]-fee+helper(prices,ind+1,1,fee,dp));
        }
        
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        
        return helper(prices,0,1,fee,dp);
        
    }
};