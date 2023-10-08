class Solution {
public:
    
    long long helper(vector<vector<int>>& grid,int i,int j,vector<vector<long long>>& dp)
    {
        if(i == 0 && j == 0)
        {
            return grid[0][0];
        }
        
        if(i < 0 || j < 0)
        {
            return 1e9;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];    
        }
        
        long long up = grid[i][j] + helper(grid,i-1,j,dp);
        long long left = grid[i][j] + helper(grid,i,j-1,dp);
        
        return dp[i][j] = min(up,left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<long long>>dp(grid.size()+1,vector<long long>(grid[0].size()+1,-1));
        
        return helper(grid,grid.size()-1,grid[0].size()-1,dp);
        
    }
};