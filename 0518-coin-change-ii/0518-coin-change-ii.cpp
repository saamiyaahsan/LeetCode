class Solution {
public:
    
    int func(vector<int>& coins,int ind,int amt,vector<vector<int>>& dp)
    {
        if(ind == 0)
        {
            if(amt % coins[ind] == 0)
            {
                return 1;
            }
            
            else
            {
                return 0;
            }
        }
        
        if(dp[ind][amt] != -1)
        {
            return dp[ind][amt];
        }
        
        int nottake = func(coins,ind-1,amt,dp);
        
        int take = 0;
        
        if(coins[ind] <= amt)
        {
            take = func(coins,ind,amt-coins[ind],dp);
        }
        
        return dp[ind][amt] = take + nottake;
    }
    
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        
        return func(coins,coins.size()-1,amount,dp);
    }
};