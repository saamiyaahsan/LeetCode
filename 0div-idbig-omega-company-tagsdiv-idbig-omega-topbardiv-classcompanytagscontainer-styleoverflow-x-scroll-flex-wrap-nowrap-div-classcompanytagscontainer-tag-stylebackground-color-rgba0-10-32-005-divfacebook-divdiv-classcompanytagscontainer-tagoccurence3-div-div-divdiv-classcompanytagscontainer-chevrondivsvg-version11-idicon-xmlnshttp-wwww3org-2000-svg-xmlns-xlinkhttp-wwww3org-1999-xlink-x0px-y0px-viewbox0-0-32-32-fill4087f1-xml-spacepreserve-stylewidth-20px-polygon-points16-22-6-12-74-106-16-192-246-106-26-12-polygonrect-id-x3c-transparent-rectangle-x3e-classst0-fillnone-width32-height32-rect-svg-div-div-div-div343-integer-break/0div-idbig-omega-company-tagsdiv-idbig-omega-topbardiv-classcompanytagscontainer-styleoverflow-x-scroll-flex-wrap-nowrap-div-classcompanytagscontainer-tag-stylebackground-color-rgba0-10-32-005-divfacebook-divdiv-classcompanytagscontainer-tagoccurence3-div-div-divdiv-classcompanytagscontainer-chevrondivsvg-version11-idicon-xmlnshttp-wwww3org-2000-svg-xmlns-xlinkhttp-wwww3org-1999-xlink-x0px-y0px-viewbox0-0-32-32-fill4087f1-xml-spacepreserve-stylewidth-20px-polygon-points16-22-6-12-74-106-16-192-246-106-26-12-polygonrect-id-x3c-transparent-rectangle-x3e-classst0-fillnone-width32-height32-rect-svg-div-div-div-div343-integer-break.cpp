class Solution {
public:
    
    int helper(int num,vector<int>& dp)
    {
        if(num <= 3)
        {
            return num;
        }
        
        if(dp[num] != -1)
        {
            return dp[num];
        }
        
        int ans = num;
        
        for(int i=2;i<num;i++)
        {
            ans = max(ans,i*helper(num-i,dp));
        }
        
        return dp[num] = ans;
    }
    
    int integerBreak(int n) {
      
        vector<int>dp(n+1,-1);
        
        if(n <= 3)
        {
            return n-1;
        }
        
        return helper(n,dp);
    }
};