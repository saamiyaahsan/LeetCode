class Solution {
public:
    
    int func(vector<int>& nums,int ind,vector<int>& dp)
    {
        if(ind == nums.size()-1)
        {
            return 1;
        }
        
        if(ind >= nums.size())
        {
            return 0;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        for(int j = ind+1;j<=ind + nums[ind];j++)
        {
            int x = func(nums,j,dp);
            
            if(x == 1)
            {
                return dp[ind] = 1;
            }
        }
        
        return dp[ind] = 0;
    }
    bool canJump(vector<int>& nums) {
        
        vector<int>dp(nums.size(),-1);
        
        int ans;
        
        ans = func(nums,0,dp);
        
        if(ans == 1)
        {
            return true;
        }
        
        return false;
    }
};