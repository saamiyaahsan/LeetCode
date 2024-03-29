class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size(), m = word2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
                else
                {
                    if(word1[i-1] == word2[j-1])
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    
                    else
                    {
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        
        int ans,res;
        
        ans = dp[n][m];
        
        res = word1.size()+word2.size()-(2*ans);
        
        return res;
    }
};