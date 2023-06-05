class Solution {
public:
    
    int helper(vector<vector<int>>& dungeon,int i,int j,vector<vector<int>>& dp)
    {
        if(i >= dungeon.size() || j >= dungeon[0].size())
        {
            return INT_MAX;
        }
        
        if(i == dungeon.size()-1 && j == dungeon[0].size()-1)
        {
            if(dungeon[i][j] > 0)
            {
                return dp[i][j] = 1;
            }
            
            else
            {
                return dp[i][j] = -dungeon[i][j] + 1;
            }
        }
        
        if(dp[i][j] != INT_MAX)
        {
           return dp[i][j];    
        }
        
        int x = helper(dungeon,i+1,j,dp);
        int y = helper(dungeon,i,j+1,dp);
        
        int c = min(x,y) - dungeon[i][j];
        
        if(c > 0)
        {
            return dp[i][j] = c;
        }
        
        else
        {
            return dp[i][j] = 1;
        }
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        vector<vector<int>>dp(dungeon.size(),vector<int>(dungeon[0].size(),INT_MAX));
        
        return helper(dungeon,0,0,dp);
        
    }
};