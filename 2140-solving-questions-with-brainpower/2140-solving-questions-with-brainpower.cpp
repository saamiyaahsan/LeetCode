class Solution {
public:
    
    long long helper(int ind,vector<vector<int>>& questions,vector<long long>& dp)
    {
        if(ind >= questions.size())
        {
            return 0;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        long long NotTake = helper(ind+1,questions,dp);
        long long Take = questions[ind][0] + helper(ind+questions[ind][1]+1,questions,dp);
        
        return dp[ind] = max(NotTake,Take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        
        vector<long long>dp(questions.size(),-1);
        
        return helper(0,questions,dp);
    }
};