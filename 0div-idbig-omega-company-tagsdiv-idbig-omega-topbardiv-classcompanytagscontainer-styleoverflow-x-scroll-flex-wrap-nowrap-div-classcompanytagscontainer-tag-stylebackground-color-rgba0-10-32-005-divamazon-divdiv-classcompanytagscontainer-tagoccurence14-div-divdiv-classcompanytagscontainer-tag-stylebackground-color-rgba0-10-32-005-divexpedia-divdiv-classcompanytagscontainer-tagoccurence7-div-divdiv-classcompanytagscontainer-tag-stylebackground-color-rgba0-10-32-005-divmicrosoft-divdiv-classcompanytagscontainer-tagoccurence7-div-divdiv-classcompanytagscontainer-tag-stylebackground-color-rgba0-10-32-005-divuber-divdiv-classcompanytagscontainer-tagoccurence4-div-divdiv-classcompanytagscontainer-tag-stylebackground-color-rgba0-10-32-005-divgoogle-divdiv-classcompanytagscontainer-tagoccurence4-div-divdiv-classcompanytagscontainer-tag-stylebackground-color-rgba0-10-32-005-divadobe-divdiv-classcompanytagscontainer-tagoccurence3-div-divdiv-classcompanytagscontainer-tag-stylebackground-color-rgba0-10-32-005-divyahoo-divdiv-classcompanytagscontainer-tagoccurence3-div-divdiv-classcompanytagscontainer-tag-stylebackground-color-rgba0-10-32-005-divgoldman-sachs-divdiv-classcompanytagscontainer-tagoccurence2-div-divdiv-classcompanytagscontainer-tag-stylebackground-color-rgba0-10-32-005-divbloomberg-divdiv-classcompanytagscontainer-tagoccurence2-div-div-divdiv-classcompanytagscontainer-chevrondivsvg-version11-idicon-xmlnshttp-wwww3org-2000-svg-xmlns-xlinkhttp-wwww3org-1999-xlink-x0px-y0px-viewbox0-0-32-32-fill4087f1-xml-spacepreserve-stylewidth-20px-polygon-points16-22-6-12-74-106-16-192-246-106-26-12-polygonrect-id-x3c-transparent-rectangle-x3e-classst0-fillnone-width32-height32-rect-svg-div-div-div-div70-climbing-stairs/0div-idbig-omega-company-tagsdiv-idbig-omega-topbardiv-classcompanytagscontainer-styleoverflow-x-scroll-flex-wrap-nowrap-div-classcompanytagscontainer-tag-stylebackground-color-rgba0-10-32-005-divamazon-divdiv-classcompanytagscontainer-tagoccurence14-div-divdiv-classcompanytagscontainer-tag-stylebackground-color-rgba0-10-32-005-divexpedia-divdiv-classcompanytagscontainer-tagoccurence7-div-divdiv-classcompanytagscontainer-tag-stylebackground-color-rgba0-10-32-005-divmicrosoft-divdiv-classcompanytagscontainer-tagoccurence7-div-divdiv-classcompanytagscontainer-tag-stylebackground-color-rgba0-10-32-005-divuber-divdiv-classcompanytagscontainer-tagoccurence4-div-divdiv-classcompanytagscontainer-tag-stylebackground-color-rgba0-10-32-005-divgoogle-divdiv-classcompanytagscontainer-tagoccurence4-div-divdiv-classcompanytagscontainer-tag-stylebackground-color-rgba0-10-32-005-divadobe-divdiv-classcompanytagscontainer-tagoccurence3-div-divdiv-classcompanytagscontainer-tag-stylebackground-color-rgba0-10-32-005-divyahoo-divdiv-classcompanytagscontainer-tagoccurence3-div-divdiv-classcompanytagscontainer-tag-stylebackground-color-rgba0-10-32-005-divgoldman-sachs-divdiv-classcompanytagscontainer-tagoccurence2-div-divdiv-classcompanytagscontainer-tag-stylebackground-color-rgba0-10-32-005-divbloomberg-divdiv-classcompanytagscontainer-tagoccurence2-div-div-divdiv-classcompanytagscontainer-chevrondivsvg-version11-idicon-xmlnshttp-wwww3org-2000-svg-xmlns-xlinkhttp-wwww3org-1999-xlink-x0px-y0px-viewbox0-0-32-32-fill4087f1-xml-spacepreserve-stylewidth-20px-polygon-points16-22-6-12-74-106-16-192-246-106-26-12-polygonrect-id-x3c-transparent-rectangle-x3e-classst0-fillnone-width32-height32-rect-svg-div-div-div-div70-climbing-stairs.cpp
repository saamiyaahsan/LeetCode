class Solution {
public:
    
    int helper(int num,vector<int>& dp)
    {
        if(num <= 2)
        {
            return num;
        }
        
        if(dp[num] != -1)
        {
            return dp[num];
        }
        
        int one = helper(num-1,dp);
        int two = helper(num-2,dp);
        
        return dp[num] = one + two;
    }
    
    int climbStairs(int n) {
        
        vector<int>dp(n+1,-1);
        
        return helper(n,dp);
        
    }
};