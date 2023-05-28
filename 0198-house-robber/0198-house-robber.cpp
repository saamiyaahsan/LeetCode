class Solution {
public:
    
    int helper(int n,vector<int>& nums,vector<int>& dp)
    {
        if(n == 0)
        {
            return nums[0];
        }
        
        if(n == 1)
        {
            return max(nums[0],nums[1]);
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        dp[n] = max(helper(n-1,nums,dp),nums[n] + helper(n-2,nums,dp));
        
        return dp[n];
    }
    int rob(vector<int>& nums) {
        
        vector<int>dp(nums.size(),-1);
        
        int n = nums.size();
        
        if(nums.size() == 1)
        {
           dp[0] = nums[0];    
        }
        
        if(nums.size() == 2)
        {
            dp[0] = nums[0];
            dp[1] = max(nums[0],nums[1]);
        }
        
        helper(n-1,nums,dp);
        
        
        return dp[n-1];
    }
};