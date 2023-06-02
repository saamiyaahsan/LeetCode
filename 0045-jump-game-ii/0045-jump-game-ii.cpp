class Solution {
public:
    
    int helper(vector<int>& nums,int ind,vector<int>& dp)
    {
        if(ind >= nums.size())
        {
            return INT_MAX;
        }
        
        if(ind == nums.size()-1)
        {
            return 0;
        }
        
        if(dp[ind] != INT_MAX)
        {
            return dp[ind];
        }
        
        for(int k = ind + 1;k <= ind + nums[ind];k++)
        {
            if(helper(nums,k,dp) != INT_MAX)
            {
                int x = 1 + helper(nums,k,dp);
                dp[ind] = min(x,dp[ind]);     
            }
           
        }
        
        return dp[ind];
    }
    
    int jump(vector<int>& nums) {
        
        vector<int>dp(nums.size(),INT_MAX);
        
        return helper(nums,0,dp);
    }
};