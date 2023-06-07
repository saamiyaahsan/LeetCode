class Solution {
public:
    
    static bool myComp(string &s1,string &s2)
    {
       return s1.size() < s2.size();    
    }
    
    bool isCompare(string &s1,string &s2)
    {
        int n = s1.size();
        int m = s2.size();
        
        if(n != m+1)
        {
            return false;
        }
        
        int i=0,j=0;
        
        while(i < n)
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
            }
            
            else
            {
                i++;
            }
        }
        
        return (i == n && j == m);
    }
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),myComp);
        
        int n = words.size();
        int res = 1;
        
        vector<int>dp(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isCompare(words[i],words[j]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
            
             res = max(res,dp[i]);
        }
        
        return res;
    }
};