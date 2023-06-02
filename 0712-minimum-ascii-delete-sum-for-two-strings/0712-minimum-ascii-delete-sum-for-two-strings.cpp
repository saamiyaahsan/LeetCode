class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        
        int sum1 = 0,sum2 = 0;
        
        for(int i=0;i<s1.size();i++)
        {
            sum1 = sum1 + s1[i];
        }
        
        for(int i=0;i<s2.size();i++)
        {
            sum2 = sum2 + s2[i];
        }
        
        for(int i=0;i<s1.size()+1;i++)
        {
            for(int j=0;j<s2.size()+1;j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
                else
                {
                    if(s1[i-1] == s2[j-1])
                    {
                        dp[i][j] = s1[i-1] + dp[i-1][j-1];
                    }
                    
                    else
                    {
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        int n = s1.size(),m = s2.size();
        
        return sum1 + sum2 - (2*dp[n][m]);
    }
};