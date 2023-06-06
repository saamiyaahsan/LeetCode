class Solution {
public:
    
//     int helper(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp)
//     {
//         if(ind == prices.size())
//         {
//             return 0;
//         }
        
//         if(dp[ind][buy] != -1)
//         {
//            return dp[ind][buy];    
//         }
        
//         int profit = 0,profit1 = 0,profit2 = 0;
        
//         if(buy == 1)
//         {
//             int x = -prices[ind] + helper(ind+1,0,prices,dp);
//             int y = helper(ind+1,1,prices,dp);
            
//             profit1 = max(x,y);
//         }
        
//         else
//         {
//             int x = prices[ind] + helper(ind+1,1,prices,dp);
//             int y = helper(ind+1,0,prices,dp);
            
//             profit2 = max(x,y);
//         }
        
//         profit = max(profit1,profit2);
        
//         return profit;
//     }
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        
        int n = prices.size();
        
        for(int i=0;i<2;i++)
        {
            dp[n][i] = 0;
        }
        
        
        // j corresponds to buy;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j == 1)
                {
                    dp[i][j] = max(dp[i+1][0] - prices[i],dp[i+1][1]);
                }
                
                else
                {
                    dp[i][j] = max(dp[i+1][1] + prices[i],dp[i+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};