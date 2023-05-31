class Solution {
public:
    
    bool ishelper(vector<int>& nums,int idx,int target,vector<vector<int>>& dp)
    {
       if(target == 0)   
       {
           return true;
       }
        
       if(idx == 0)
       {
           return (nums[0] == target);
       }
        
       if(dp[idx][target] != -1) 
       {
           return dp[idx][target];   
       }
        
       bool notTake = ishelper(nums,idx-1,target,dp);
        
       bool Take = false;
       
       if(target >= nums[idx]) 
       {
           Take = ishelper(nums,idx-1,target-nums[idx],dp);
       }
        
        return dp[idx][target] = Take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
        }
        
        if(sum % 2 == 1)
        {
            return false;
        }
        
          vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
          
        return ishelper(nums,nums.size()-1,sum/2,dp);
    }
};