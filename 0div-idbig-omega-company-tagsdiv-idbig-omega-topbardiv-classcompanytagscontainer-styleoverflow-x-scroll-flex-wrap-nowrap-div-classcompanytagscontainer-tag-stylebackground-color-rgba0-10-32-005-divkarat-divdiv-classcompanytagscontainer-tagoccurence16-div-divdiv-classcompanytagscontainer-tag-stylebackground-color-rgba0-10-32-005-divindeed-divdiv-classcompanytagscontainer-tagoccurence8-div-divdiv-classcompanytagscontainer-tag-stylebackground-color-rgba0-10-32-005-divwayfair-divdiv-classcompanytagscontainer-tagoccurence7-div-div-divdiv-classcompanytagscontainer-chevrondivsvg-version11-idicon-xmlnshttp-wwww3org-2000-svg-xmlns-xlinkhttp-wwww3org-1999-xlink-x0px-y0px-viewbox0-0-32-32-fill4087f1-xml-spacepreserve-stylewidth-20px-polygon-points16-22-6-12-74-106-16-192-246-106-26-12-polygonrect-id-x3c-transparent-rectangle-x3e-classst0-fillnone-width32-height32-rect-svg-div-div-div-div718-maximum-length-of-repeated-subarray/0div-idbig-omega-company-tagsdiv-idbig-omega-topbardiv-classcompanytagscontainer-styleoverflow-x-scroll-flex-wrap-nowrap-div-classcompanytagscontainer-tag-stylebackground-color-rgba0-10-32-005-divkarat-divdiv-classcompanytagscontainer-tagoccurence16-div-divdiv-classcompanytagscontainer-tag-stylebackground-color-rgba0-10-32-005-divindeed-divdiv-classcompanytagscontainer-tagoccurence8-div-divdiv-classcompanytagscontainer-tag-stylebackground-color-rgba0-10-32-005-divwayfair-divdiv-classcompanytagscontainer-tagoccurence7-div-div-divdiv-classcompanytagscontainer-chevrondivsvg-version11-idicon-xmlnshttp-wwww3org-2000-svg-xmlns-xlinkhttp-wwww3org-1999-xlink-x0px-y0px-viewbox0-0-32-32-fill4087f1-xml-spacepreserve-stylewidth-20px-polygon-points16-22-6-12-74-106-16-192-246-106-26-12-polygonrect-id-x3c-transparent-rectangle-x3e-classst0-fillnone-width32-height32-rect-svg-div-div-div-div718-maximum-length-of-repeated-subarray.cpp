class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        
        int ans = 0;
        
        for(int i=0;i<=nums1.size();i++)
        {
            for(int j=0;j<=nums2.size();j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
                else if(nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=0;i<=nums1.size();i++)
        {
            for(int j=0;j<=nums2.size();j++)
            {
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
};