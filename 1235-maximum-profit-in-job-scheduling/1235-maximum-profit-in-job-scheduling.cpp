class Solution {
public:
    
    int helper(vector<vector<int>>& job,int ind,int last_end_time,vector<int>& dp)
    {
        if(ind >= job.size())
        {
            return 0;
        }
        
        if(job[ind][0] < last_end_time)
        {
            return helper(job,ind+1,last_end_time,dp);
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        int take = job[ind][2] + helper(job,ind+1,job[ind][1],dp);
        int notTake = helper(job,ind+1,last_end_time,dp);
        
        return dp[ind] = max(take,notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>>job;
        
        vector<int>dp(startTime.size(),-1);
        
        for(int i=0;i<startTime.size();i++)
        {
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        
        sort(job.begin(),job.end());
        
        return helper(job,0,0,dp);
    }
};