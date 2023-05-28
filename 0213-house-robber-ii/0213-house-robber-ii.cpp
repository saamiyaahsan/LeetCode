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
        
        dp[n] = max(helper(n-1,nums,dp),nums[n]+helper(n-2,nums,dp));
        return dp[n];
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        vector<int>a;
        vector<int>b;
        
        vector<int>dp1(nums.size()-1,-1);
        vector<int>dp2(nums.size()-1,-1);
        
        for(int i=0;i<nums.size()-1;i++)
        {
            a.push_back(nums[i]);
        }
        
        for(int i=1;i<nums.size();i++)
        {
            b.push_back(nums[i]);
        }
        
        dp1[0] = nums[0];
        
        if(nums.size() > 2)
        {
            dp1[1] = max(nums[0],nums[1]);    
        }
        
        if(nums.size() > 1)
        {
            dp2[0] = nums[1];    
        }
        
        if(nums.size() >= 3)
        {
            dp2[1] = max(nums[1],nums[2]);     
        }
       
        helper(a.size()-1,a,dp1);
        helper(b.size()-1,b,dp2);
        
        return max(dp1[nums.size()-2],dp2[nums.size()-2]);
    }
};