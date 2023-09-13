class Solution {
public:
    
    double helper(int i,int j,int k,int n,vector<vector<vector<double>>>& dp)
    {
        if(i < 0 || i >= n || j < 0 || j >= n)
        {
            return 0;
        }
        
        if(k == 0)
        {
            return 1;
        }
        
        if(dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        
        vector<int>drow = {-2,-2,-1,-1,1,1,2,2};
        vector<int>dcol = {-1,1,-2,2,-2,2,-1,1};
        
        double ans = 0;
        
        for(int m=0;m<8;m++)
        {
            ans = ans + helper(i+drow[m],j+dcol[m],k-1,n,dp);
        }
        
        ans = ans/8;
        
        return dp[i][j][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
       
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        
       return helper(row,column,k,n,dp);
        
    }
};