class Solution {
public:
    
    int helper(int target,int base,int x,vector<vector<int>>& dp)
    {
        if(target == 0)
        {
            return 1;
        }
        
        if(target < 0)
        {
            return 0;
        }
        
        if(target < pow(base,x))
        {
            return 0;
        }
        
        if(dp[base][target] != -1)
        {
            return dp[base][target];
        }
        
        int nottake = helper(target,base+1,x,dp);
        int take = 0;
        
        if(target - pow(base,x) >= 0)
        {
            take = helper(target-pow(base,x),base+1,x,dp);
        }
        
        return dp[base][target] = (nottake + take) % 1000000007;
    }
    
    int numberOfWays(int n, int x) {
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return helper(n,1,x,dp);
    }
};