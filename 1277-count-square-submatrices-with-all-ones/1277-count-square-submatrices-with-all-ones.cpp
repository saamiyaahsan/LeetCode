class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i == 0 || j == 0 || matrix[i][j] == 0)
                {
                    dp[i][j] = matrix[i][j];
                }
                
                else
                {
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
                }
            }
        }
        
        int sum = 0;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                sum = sum + dp[i][j];
            }
        }
        
        return sum;
    }
};