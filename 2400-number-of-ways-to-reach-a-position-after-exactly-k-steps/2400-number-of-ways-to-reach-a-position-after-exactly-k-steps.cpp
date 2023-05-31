class Solution {
public:
    
    int dp[3000][3000];
    long mod = 1e9+7;
    
    int helper(int i,int startPos,int endPos,int moves)
    {
        if(i == endPos && moves == 0)
        {
            return 1;
        }
        
         if(moves <= 0)
        {
            return 0;
        }
        
        if(dp[i+1000][moves] != -1)
        {
            return dp[i+1000][moves];    
        }
        
        long res = 0;
        
        res += helper(i+1,startPos,endPos,moves-1);
        res += helper(i-1,startPos,endPos,moves-1);
        
        dp[i+1000][moves] = res % mod;     
            
        return dp[i+1000][moves]; 
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        
        memset(dp,-1,sizeof(dp));
        
        return helper(startPos,startPos,endPos,k);
        
    }
};