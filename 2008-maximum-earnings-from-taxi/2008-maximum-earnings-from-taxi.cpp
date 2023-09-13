class Solution {
public:
    
    int lowerBound(vector<vector<int>>& rides,int ind,int key)
    {
        int low = ind,high = rides.size()-1;
        
        int ans = rides.size();
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(rides[mid][0] >= key)
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
    
    long long helper(vector<vector<int>>& rides,int ind,vector<long long>& dp)
    {
        if(ind >= rides.size())
        {
            return 0;
        }
        
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        
        int curr_index = lowerBound(rides,ind,rides[ind][1]);
        
        long long notTake = helper(rides,ind+1,dp);
        long long Take = rides[ind][1]-rides[ind][0]+rides[ind][2] + helper(rides,curr_index,dp);
        
        return dp[ind] = max(notTake,Take);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
       
        vector<long long>dp(rides.size(),-1);
        
        sort(rides.begin(),rides.end());
    
        return helper(rides,0,dp);
    }
    
};