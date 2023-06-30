class Solution {
public:
    
    int helper(int ind,int lane,vector<int>& obstacles,vector<vector<int>>& dp)
    {
        if(ind == obstacles.size()-1)
        {
            return 0;
        }
        
        if(dp[lane][ind] != -1)
        {
           return dp[lane][ind];    
        }
          
        if(obstacles[ind+1] != lane)
        {
            dp[lane][ind] = helper(ind+1,lane,obstacles,dp);
            return dp[lane][ind];
        }
        
             int ans = INT_MAX;
        
            for(int i=1;i<=3;i++)
            {
                if(lane != i && obstacles[ind] != i)
                {
                    int p = 1 + helper(ind+1,i,obstacles,dp);
                    ans = min(ans,p);
                }
            }
            
          return dp[lane][ind] = ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        
        vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
        
        return helper(0,2,obstacles,dp);
        
    }
};