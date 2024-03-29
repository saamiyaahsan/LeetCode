class Solution {
public:
    
    int helper(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>>& dp)
    {
        if(i == 0 && j == 0 && obstacleGrid[i][j] == 0)
        {
            return 1;
        }
        
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int up = helper(obstacleGrid,i-1,j,dp);
        int left = helper(obstacleGrid,i,j-1,dp);
        
        return dp[i][j] = up + left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        return helper(obstacleGrid,m-1,n-1,dp);
        
    }
};