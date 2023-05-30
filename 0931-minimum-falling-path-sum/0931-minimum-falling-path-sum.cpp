class Solution {
public:
    
    int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
         if(j < 0 || j >= matrix[0].size())
        {
            return 1e9;
        }
        
        
        if(i == 0)
        {
            return matrix[i][j];
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
             int up = matrix[i][j] + helper(i-1,j,matrix,dp);    
             int leftup = matrix[i][j] + helper(i-1,j-1,matrix,dp);     
             int rightup = matrix[i][j] + helper(i-1,j+1,matrix,dp);     
        
        return dp[i][j] = min({up,leftup,rightup});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
       
        int n = matrix.size(), m = matrix[0].size();
        
        
        
        int ans = INT_MAX;
        
        for(int i=0;i<matrix[0].size();i++)
        {
            vector<vector<int>>dp(n,vector<int>(m,-1));
            ans = min(ans,helper(matrix.size()-1,i,matrix,dp));
        }
        
        return ans;
    }
};