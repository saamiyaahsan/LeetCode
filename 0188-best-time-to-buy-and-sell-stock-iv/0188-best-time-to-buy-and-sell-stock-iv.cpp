class Solution {
public:
    
     int helper(int ind,int buy,int transactions,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(ind == prices.size() || transactions == 0)
        {
            return 0;
        }
        
        if(dp[ind][buy][transactions] != -1)
        {
            return dp[ind][buy][transactions];
        }
        
        int profit = 0;
        
        if(buy == 1)
        {
            int x = -prices[ind] + helper(ind+1,0,transactions,prices,dp);
            int y = helper(ind+1,1,transactions,prices,dp);
            
            profit = max(x,y);
        }
        
        else
        {
                int x = prices[ind] + helper(ind+1,1,transactions-1,prices,dp);
                int y = helper(ind+1,0,transactions,prices,dp);
                profit = max(x,y);      
        }
        
        dp[ind][buy][transactions] = profit;
    
    return dp[ind][buy][transactions];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
          vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        
        return helper(0,1,k,prices,dp);
        
        
    }
};