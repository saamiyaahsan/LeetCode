class Solution {
public:
    
    int helper(string s,int ind,vector<int>& dp)
    {
        if(ind == s.size())
        {
            return 1;
        }
        
        if(ind > s.size())
        {
            return 0;
        }
         
         if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        
        if(s[ind] == '0')
        {
            return dp[ind]= 0;
        }
        
       
        if(ind < s.size()-1 && ((s[ind+1] <= '6' && s[ind] == '2') || s[ind] == '1'))
        {
            return dp[ind] = helper(s,ind+1,dp) + helper(s,ind+2,dp);
        }
    
        return dp[ind] = helper(s,ind+1,dp);
    }
    
    int numDecodings(string s) {
        
        vector<int>dp(s.size(),-1);
        
        return helper(s,0,dp);
        
    }
};