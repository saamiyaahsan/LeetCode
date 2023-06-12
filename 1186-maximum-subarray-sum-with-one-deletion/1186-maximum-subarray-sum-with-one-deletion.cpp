class Solution {
public:
    
    int helper(vector<int>& arr,int ind,int del,vector<vector<int>>& dp)
    {
       if(ind == arr.size()-1)
       {
           return arr[ind];
       }
       
       if(dp[ind][del] != -1) 
       {
           return dp[ind][del];
       }
        
       int NotDelete = arr[ind] + helper(arr,ind+1,del,dp);
       int Delete = INT_MIN;
       int only_One = arr[ind];
        
        if(del == 1)
        {
            Delete = helper(arr,ind+1,del-1,dp);
        }
        
        return dp[ind][del] = max({Delete,NotDelete,only_One});
    }
    
    int maximumSum(vector<int>& arr) {
        
        int ans = INT_MIN;
        
        vector<vector<int>>dp(arr.size(),vector<int>(2,-1));
        
        for(int i=0;i<arr.size();i++) 
        {
          ans = max(ans,helper(arr,i,1,dp));   
        }
        
        return ans;
        
    }
};