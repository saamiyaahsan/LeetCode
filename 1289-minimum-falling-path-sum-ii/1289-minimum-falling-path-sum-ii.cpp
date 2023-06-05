class Solution {
public:
    
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i == 0)
        {
            return grid[i][j];
        }
        
        if(dp[i][j] != -1)
        {
           return dp[i][j];    
        }
        
        int ans = INT_MAX;
        
        for(int k=0;k<grid[0].size();k++)
        {
            if(k != j)
            {
                ans = min(ans,helper(i-1,k,grid,dp)+grid[i][j]);
            }
        }
        
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int res = INT_MAX;
        
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        
        for(int i=0;i<grid[0].size();i++)
        {
            res = min(res,helper(grid.size()-1,i,grid,dp));
        }
        
        return res;
        
    }
};