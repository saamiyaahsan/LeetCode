class Solution {
public:
    
    long long helper(string s1,string s2)
    {
        vector<vector<long long>>dp(s1.size()+1,vector<long long>(s2.size()+1,-1));
        
        for(int i=0;i<=s1.size();i++)
        {
            for(int j=0;j<=s2.size();j++)
            {
                if(i == 0 && j != 0)
                {
                    dp[i][j] = 0;
                }
                
                else if(j == 0)
                {
                    dp[i][j] = 1;
                }
                
                else
                {
                    if(s1[i-1] == s2[j-1])
                    {
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                    }
                    
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[s1.size()][s2.size()];
    }
    
    long long maximumSubsequenceCount(string text, string pattern) {
        
        long long x = helper(text+pattern[1],pattern);
        long long y = helper(pattern[0]+text,pattern);
        
        return max(x,y);
    }
};