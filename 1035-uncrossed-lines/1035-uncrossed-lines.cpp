class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        
        for(int i=0;i<nums1.size()+1;i++)
        {
            for(int j=0;j<nums2.size()+1;j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
                else if( i > 0 && j > 0 && nums1[i-1] == nums2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else if(i > 0 && j > 0 && nums1[i-1] != nums2[j-1])
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[nums1.size()][nums2.size()];
    }
};