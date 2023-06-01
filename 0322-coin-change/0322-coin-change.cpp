class Solution {
public:
    
    int helper(vector<int>& coins,int ind,int amt,vector<vector<int>>& dp)
    {
        if(ind == 0)
        {   
            if(amt % coins[0] == 0)
            {
                 return int (amt/coins[0]) ;     
            }
            
            else
            {
               return 1e9;    
            }
            
        }
        
        if(dp[ind][amt] != -1)
        {
            return dp[ind][amt];
        }
        
        int nottake = helper(coins,ind-1,amt,dp);
        int take = 1e9;
        
        if(coins[ind] <= amt)
        {
            take = 1 + helper(coins,ind,amt-coins[ind],dp);
        }
        
        dp[ind][amt] = min(take,nottake);
     
       return dp[ind][amt]; 
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        
        int p = helper(coins,coins.size()-1,amount,dp);
        
        if(p == 1e9)
        {
            return -1;
        }
        
        return p;
    }
};