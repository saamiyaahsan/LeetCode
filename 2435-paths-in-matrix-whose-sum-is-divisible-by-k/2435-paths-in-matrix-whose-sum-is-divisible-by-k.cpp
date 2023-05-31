class Solution {
public:
    
    long mod = 1e9+7;
    
    int helper(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp,int i,int j,int sum,int k)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        {
            return 0;
        }
        
        if(i == grid.size()-1 && j == grid[0].size()-1)
        {
            sum = (sum + grid[i][j]) % k;
            
            if(sum % k == 0)
            {
                return 1;
            }
            
            else if(k == 1)
            {
                return 1;    
            }
            
            else
            {
                return 0;
            }
        }
        
        if(dp[i][j][sum] != -1)
        {
           return dp[i][j][sum];    
        }
        
        return dp[i][j][sum % k] = (helper(grid,dp,i+1,j,(sum + grid[i][j])%k,k) + helper(grid,dp,i,j+1,(sum + grid[i][j])%k,k)) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        vector<vector<vector<int>>>dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(k+1,-1)));
        
        return helper(grid,dp,0,0,0,k);
        
    }
};