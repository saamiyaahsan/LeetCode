class Solution {
public:
    
    int helper(vector<int>& weights,int capacity)
    {
        int wt = 0,total_day=1;
        
        for(int i=0;i<weights.size();i++)
        {
            wt = wt + weights[i];
            
            if(wt > capacity)
            {
                total_day++;
                wt = weights[i];
            }
        }
        
        return total_day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int totalWt = 0,maxi = 0,ans = 0;
        
        for(int i=0;i<weights.size();i++)
        {
            totalWt = totalWt + weights[i];
            maxi = max(maxi,weights[i]);
        }
        
        int low,high;
        
        low = maxi;
        high = totalWt;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(helper(weights,mid) <= days)
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
};