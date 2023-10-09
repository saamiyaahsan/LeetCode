class Solution {
public:
    
    int LCS(string text1,string text2,int i,int j,vector<vector<int>>& dp)
    {
        if(i == 0 || j == 0)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(text1[i-1] == text2[j-1])
        {
            return dp[i][j] = 1 + LCS(text1,text2,i-1,j-1,dp);
        }
        
        return dp[i][j] = max(LCS(text1,text2,i-1,j,dp),LCS(text1,text2,i,j-1,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
      
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        
        //return LCS(text1,text2,text1.size(),text2.size(),dp);
    
         for(int i=0;i<=text1.size();i++)
         {
             for(int j=0;j<=text2.size();j++)
             {
                 if(i == 0 || j == 0)
                 {
                     dp[i][j] = 0;
                 }
                 
                 else if(text1[i-1] == text2[j-1])
                 {
                     dp[i][j] = 1 + dp[i-1][j-1];
                 }
                 
                 else if(text1[i-1] != text2[j-1])
                 {
                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                 }
             }
         }
        
         return dp[text1.size()][text2.size()]; 
        
    }
    
    
};