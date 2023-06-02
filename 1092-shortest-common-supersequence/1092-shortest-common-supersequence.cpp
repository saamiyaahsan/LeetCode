class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,-1));
        
        for(int i=0;i<str1.size()+1;i++)
        {
            for(int j=0;j<str2.size()+1;j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                
                else
                {
                    if(str1[i-1] == str2[j-1])
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
        
        int i,j;
        
        i = str1.size();
        j = str2.size();
        
        string str = "";
        
        while(i > 0 && j > 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                str = str + str1[i-1];
                i--;
                j--;
            }
            
            else if(dp[i-1][j] > dp[i][j-1])
            {
                str = str + str1[i-1];
                i--;
            }
            
            else 
            {
                str = str + str2[j-1];
                j--;
            }
        }
        
        while(i > 0)
        {
             str = str + str1[i-1];
             i--;
        }
        
         while(j > 0)
        {
             str = str + str2[j-1];
             j--;
        }
        
        reverse(str.begin(),str.end());
        
        return str;
    }
};