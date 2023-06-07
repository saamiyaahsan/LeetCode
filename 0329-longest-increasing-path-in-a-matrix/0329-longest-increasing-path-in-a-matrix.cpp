class Solution {
public:
    
    int func(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        int m,n;
        
        m = matrix.size();
        n = matrix[0].size();
        
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        
        int maxi = 0;
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];    
        }
        
        for(int i=0;i<drow.size();i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && matrix[nrow][ncol] > matrix[row][col])
            {
                maxi = max(maxi,1+func(nrow,ncol,matrix,dp));
            }
        }
        
        return dp[row][col] = maxi;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       
        int ans = 0;
        
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                ans = max(ans,func(i,j,matrix,dp));
            }
        }
        
        return ans+1;
    }
};