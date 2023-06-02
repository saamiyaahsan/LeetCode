class Solution {
public:
    int minInsertions(string s) {
        
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        
        string t = "";
        t = s;
        
        reverse(t.begin(),t.end());
        
        for(int i=0;i<=s.size();i++)
        {
            for(int j=0;j<=t.size();j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
                else
                {
                    if(s[i-1] == t[j-1])
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
        
        int ans = INT_MIN;
        
        for(int i=0;i<=s.size();i++)
        {
            for(int j=0;j<=t.size();j++)
            {
                ans = max(ans,dp[i][j]);
            }
        }
        
        int res;
         
        res = s.size()-ans;
        
        return res;
    }
};