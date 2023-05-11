class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string t = s;
        
        reverse(t.begin(),t.end());
        
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
        
        for(int i=0;i<s.size()+1;i++)
        {
            for(int j=0;j<s.size()+1;j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
                else if(i > 0 && j > 0 && s[i-1] == t[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                
                else if(i > 0 && j > 0 && s[i-1] != t[j-1])
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[s.size()][s.size()];
    }
};