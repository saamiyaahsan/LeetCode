class Solution {
public:
    
    int helper(vector<int>& bloomDay,int curr_day,int k)
    {
        int cnt = 0,res=0;
        
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i] <= curr_day)
            {
                cnt++;
            }
            
            else
            {
                cnt = 0;
            }
            
            if(cnt == k)
            {
                res++;
                cnt = 0;
            }
            
        }
        
        return res;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int maxi = 0;
        
        for(int i=0;i<bloomDay.size();i++)
        {
            maxi = max(maxi,bloomDay[i]);
        }
        
        int low = 1,high = maxi,ans=-1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(helper(bloomDay,mid,k) >= m)
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