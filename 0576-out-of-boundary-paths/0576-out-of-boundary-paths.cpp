class Solution {
public:
   int dp[51][51][51];
    long mod = 1e9+7;
    
    int dfs(int i,int j,int moves,int m,int n)
    {
        if(i >= m || j >= n || i < 0 || j < 0)
        {
            return 1;
        }   
        
        if(moves == 0)
        {
            return 0;
        }
            
        if(dp[i][j][moves] != -1)
        {
            return dp[i][j][moves];
        }
            
        
        long res = 0;
        
        res += dfs(i-1,j,moves-1,m,n);
        res += dfs(i+1,j,moves-1,m,n);
        res += dfs(i,j-1,moves-1,m,n);
        res += dfs(i,j+1,moves-1,m,n);
        
        return dp[i][j][moves] = res % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        
        return dfs(startRow,startColumn,maxMove,m,n);
    }
};