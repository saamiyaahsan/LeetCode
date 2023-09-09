class Solution {
public:
    
    int helper(int n,vector<int>& dp)
    {
        if(n == 0)
        {
            return 0;
        }
     
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        int ans = INT_MAX;
        
        for(int i=1;i*i<=n;i++)
        {
            if(n - pow(i,2) >= 0)
            {
               ans = min(ans,1 + helper(n-pow(i,2),dp));    
            }
            
        }
        
        return dp[n] = ans;
    }
    int numSquares(int n) {
        
        vector<int>dp(n+1,-1);
        
        return helper(n,dp);
        
    }
};