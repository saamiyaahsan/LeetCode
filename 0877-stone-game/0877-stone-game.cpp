class Solution {
public:
    
    int helper(vector<int>& piles,int i,int j,vector<vector<int>>& dp)
    {
        if(i == j-1)
        {
            return max(piles[i],piles[j]);
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int isLeft = piles[i] + helper(piles,i+1,j,dp);
        int isRight = piles[j] + helper(piles,i,j-1,dp);
        
        return  dp[i][j] = max(isLeft,isRight);
    }
    bool stoneGame(vector<int>& piles) {
        
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
        
        int sum = 0,SumforWin = 0;
        
        SumforWin = helper(piles,0,piles.size()-1,dp);
        
        for(auto it : piles)
        {
            sum = sum + it;
        }
        
        return SumforWin > (sum - SumforWin);
    }
};