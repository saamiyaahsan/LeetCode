class Solution {
public:
    
    int helper(vector<int>& nums,int ind,int target,vector<int>& dp)
    {
        if(ind == nums.size()-1)
        {
            return 0;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        int ans = INT_MIN;
        
        for(int i=ind+1;i<nums.size();i++)
        {
            if(abs(nums[i]-nums[ind]) <= target)
            {
                ans = max(ans,1+helper(nums,i,target,dp));
            }
        }
        
        return dp[ind] = ans;
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        
        vector<int>dp(nums.size(),-1);
        
        int result = helper(nums,0,target,dp);
        
        if(result > 0)
        {
            return result;
        }
        
        return -1;
    }
};