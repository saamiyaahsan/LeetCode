class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        vector<vector<int>>dp(nums.size(),vector<int>(1001,-1));
        
        int ans = INT_MIN,difference;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                difference = nums[i] - nums[j] + 500;
                dp[i][difference] = max(dp[j][difference]+1,2);
                  ans = max(ans,dp[i][difference]);
            }
            
        }
        
        return ans;
    }
};