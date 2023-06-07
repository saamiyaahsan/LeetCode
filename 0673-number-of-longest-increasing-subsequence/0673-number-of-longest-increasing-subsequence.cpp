class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        vector<int>dp(nums.size(),1);
        vector<int>cnt(nums.size(),1);
        
        int ans = 1,res = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                
                else if(nums[i] > nums[j] && dp[i] == dp[j] + 1)
                {
                    cnt[i] = cnt[i] + cnt[j];
                }
            }
            
            ans = max(ans,dp[i]);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(dp[i] == ans)
            {
                res = res + cnt[i];
            }
        }
        
        return res;
    }
};