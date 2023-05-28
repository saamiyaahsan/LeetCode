class Solution {
public:
    
    int helper(vector<int>& dp,int n)
    {
        if(n <= 2)
        {
            return n;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        int left =  helper(dp,n-1);
        int right = helper(dp,n-2);
        
        dp[n] = left + right;
        
        return dp[n];
    }
    
    int climbStairs(int n) {
    
        vector<int>dp(n+1,-1);
        
        return helper(dp,n);
        
    }
};