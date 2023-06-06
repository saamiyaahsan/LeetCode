class Solution {
public:
    
    int helper(int ind,int prev_ind,vector<vector<int>>& dp,vector<int>& nums)
    {
        if(ind == nums.size())
        {
            return 0;
        }
        
        if(dp[ind][prev_ind+1] != -1)
        {
            return dp[ind][prev_ind+1];    
        }
        
        int notTake = helper(ind+1,prev_ind,dp,nums);
        int take = INT_MIN;
        
        if(prev_ind == -1 || nums[ind] > nums[prev_ind])
        {
           take =  1 + helper(ind+1,ind,dp,nums);    
        }
        
        return dp[ind][prev_ind+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        
        return helper(0,-1,dp,nums);
        
    }
};