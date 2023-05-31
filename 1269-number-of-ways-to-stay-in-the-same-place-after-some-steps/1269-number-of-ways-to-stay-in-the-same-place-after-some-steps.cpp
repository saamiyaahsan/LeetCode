class Solution {
public:
    
    int dp[501][1001];
    long mod = 1e9+7;
    
    int helper(int i,int moves,int arrLen)
    {
        if(i == 0 && moves == 0)
        {
            return 1;
        }
        
        if(i < 0 || i >= arrLen || moves <= 0 || i > moves)
        {
            return 0;
        }
        
        if(dp[i][moves] != -1)
        {
            return dp[i][moves];
        }
        
        long res = 0;
        
        res += helper(i,moves-1,arrLen);
        res += helper(i-1,moves-1,arrLen);
        res += helper(i+1,moves-1,arrLen);
        
        dp[i][moves] = res % mod;
        
        return dp[i][moves];
    }
    int numWays(int steps, int arrLen) {
        
        memset(dp,-1,sizeof(dp));
        return helper(0,steps,arrLen);
        
    }
};