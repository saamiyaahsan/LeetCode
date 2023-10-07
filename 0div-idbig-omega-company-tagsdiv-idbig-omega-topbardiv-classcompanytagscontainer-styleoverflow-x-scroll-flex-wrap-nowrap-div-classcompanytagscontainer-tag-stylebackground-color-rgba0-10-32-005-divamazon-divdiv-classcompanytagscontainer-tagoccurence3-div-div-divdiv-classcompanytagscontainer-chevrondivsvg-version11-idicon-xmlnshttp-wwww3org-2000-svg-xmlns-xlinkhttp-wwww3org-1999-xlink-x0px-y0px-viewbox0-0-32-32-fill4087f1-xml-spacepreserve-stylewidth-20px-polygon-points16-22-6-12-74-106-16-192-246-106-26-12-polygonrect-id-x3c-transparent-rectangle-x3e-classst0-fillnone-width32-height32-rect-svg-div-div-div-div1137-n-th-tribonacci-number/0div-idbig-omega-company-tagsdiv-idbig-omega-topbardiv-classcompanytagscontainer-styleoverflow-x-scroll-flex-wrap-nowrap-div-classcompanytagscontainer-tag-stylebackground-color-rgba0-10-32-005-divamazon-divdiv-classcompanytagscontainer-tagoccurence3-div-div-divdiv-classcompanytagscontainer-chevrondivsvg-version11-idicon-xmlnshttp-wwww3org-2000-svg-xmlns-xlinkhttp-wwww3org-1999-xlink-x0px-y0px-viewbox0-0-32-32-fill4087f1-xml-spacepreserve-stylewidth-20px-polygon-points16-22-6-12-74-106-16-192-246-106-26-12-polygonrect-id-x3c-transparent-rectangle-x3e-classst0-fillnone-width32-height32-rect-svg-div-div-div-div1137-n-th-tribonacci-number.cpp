class Solution {
public:
    
    int tribonacci(int n) {
       
        vector<int>dp(n+1,-1);
        
        return helper(n,dp);
    }
    
    int helper(int num,vector<int>& dp)
    {
        if(num == 0)
        {
            return 0;
        }
        
        if(num == 1 || num == 2)
        {
            return 1;
        }
        
        if(dp[num] != -1)
        {
            return dp[num];
        }
        
        return dp[num] = helper(num-1,dp) + helper(num-2,dp) + helper(num-3,dp);
    }
};