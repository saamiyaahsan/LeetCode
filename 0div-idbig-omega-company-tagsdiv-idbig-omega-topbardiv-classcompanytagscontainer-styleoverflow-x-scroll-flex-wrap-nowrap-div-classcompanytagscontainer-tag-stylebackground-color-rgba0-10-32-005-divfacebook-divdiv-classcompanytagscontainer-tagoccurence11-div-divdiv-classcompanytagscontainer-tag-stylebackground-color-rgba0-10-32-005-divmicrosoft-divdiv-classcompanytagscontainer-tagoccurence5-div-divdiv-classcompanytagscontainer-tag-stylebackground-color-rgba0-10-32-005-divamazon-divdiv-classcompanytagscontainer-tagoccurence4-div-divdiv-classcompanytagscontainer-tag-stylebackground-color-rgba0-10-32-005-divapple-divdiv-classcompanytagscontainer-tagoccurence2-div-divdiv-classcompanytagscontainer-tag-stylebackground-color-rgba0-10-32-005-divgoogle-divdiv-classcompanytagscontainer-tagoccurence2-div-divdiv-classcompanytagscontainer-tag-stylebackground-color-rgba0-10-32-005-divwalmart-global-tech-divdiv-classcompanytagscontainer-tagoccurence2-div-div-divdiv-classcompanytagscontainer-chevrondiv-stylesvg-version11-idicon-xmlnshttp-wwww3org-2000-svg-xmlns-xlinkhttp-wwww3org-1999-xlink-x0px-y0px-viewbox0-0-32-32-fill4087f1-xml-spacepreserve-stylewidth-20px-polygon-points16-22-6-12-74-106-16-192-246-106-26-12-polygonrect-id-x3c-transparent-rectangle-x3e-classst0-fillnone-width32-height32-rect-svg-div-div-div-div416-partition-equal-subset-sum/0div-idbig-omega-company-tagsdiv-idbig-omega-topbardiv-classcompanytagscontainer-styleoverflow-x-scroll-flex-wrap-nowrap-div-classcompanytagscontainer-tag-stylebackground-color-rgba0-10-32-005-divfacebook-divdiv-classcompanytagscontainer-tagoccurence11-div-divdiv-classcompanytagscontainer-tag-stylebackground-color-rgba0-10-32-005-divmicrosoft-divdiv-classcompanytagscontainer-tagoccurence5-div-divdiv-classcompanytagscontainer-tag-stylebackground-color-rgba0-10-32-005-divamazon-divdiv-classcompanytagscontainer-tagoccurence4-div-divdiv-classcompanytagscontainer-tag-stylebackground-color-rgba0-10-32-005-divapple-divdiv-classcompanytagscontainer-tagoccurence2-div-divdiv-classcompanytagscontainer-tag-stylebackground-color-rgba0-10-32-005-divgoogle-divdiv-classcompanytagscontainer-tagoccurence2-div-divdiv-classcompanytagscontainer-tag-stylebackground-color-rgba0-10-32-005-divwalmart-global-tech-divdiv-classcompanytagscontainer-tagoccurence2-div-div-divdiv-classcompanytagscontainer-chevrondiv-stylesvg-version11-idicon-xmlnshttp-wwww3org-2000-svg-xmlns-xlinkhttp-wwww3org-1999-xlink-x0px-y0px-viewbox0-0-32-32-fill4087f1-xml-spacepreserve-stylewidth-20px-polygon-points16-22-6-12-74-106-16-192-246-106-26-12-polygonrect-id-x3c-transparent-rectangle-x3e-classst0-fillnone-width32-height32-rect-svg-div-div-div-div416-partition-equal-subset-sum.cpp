class Solution {
public:
    
    bool helper(vector<int>& nums,int i,int target,vector<vector<int>>& dp)
    {
        if(target == 0)
        {
            return true;
        }
        
        if(i == 0 || target < 0)
        {
            return false;
        }
        
        if(dp[i][target] != -1)
        {
            return dp[i][target];
        }
        
        int notTake = helper(nums,i-1,target,dp);
        int Take = 0;
        
        if(nums[i-1] <= target)
        {
            Take = helper(nums,i-1,target-nums[i-1],dp);
        }
        
        return dp[i][target] = notTake || Take;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0,target;
        
         for(int i=0;i<nums.size();i++)    
         {
            sum = sum + nums[i];
         }
        
         if(sum % 2 == 1)
         {
            return false;
         }
        
        target = sum/2;
        
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        
        return helper(nums,nums.size(),sum/2,dp);
        
        
    }
};