class Solution {
public:
    
    int helper(vector<int>& cost,int ind,vector<int>& dp)
    {
        if(ind >= cost.size())
        {
            return 0;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        int one = cost[ind] + helper(cost,ind+1,dp);
        int two = cost[ind] + helper(cost,ind+2,dp);
        
        return dp[ind] = min(one,two);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
      
        vector<int>dp(cost.size(),-1);
        
        int x = helper(cost,0,dp);
        int y = helper(cost,1,dp);
        
        return min(x,y);
    }
};