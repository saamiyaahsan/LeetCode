class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m));
        
        dp[0]=matrix[0];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
			    // min of up and up-right
                if(j==0){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j], dp[i-1][j+1]);
                }
				// min of up and up-left
                else if(j==m-1){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j], dp[i-1][j-1]);
                }
				// min of up, up-right and up-left
                else{
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j], min(dp[i-1][j+1], dp[i-1][j-1]));
                }
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};