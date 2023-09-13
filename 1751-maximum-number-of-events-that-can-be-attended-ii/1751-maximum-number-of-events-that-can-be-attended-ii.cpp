class Solution {
public:
    
    int lowerBound(vector<vector<int>>& events,int start,int key)
    {
        int low = start+1,high = events.size()-1;
        int ans = events.size();
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(events[mid][0] > key)
            {
                ans = mid;
                high = mid-1;
            }
            
            else
            {
                low = mid+1;
            }
        }
        
        return ans;
    }
    int helper(vector<vector<int>>& events,int ind,int k,vector<vector<int>>& dp)
    {
        if(ind == events.size())
        {
            return 0;
        }
        
        if(k == 0)
        {
            return 0;
        }
        
        if(dp[ind][k] != -1)
        {
            return dp[ind][k];
        }
        
        int curr_ind = lowerBound(events,ind,events[ind][1]);
        
        int notTake = helper(events,ind+1,k,dp);
        int take = events[ind][2] + helper(events,curr_ind,k-1,dp);
        
        return dp[ind][k] = max(take,notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1));
        
        sort(events.begin(),events.end());
        
        return helper(events,0,k,dp);
        
    }
};