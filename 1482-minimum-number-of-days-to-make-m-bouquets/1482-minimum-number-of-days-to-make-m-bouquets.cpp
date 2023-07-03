class Solution {
public:
    
    int func(vector<int>& bloomDay,int curr_day,int k)
    {
        int cnt = 0,ans = 0;
        
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
                ans++;
                cnt = 0;
            }
        }
        
        return ans;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
    int low = *min_element(bloomDay.begin(),bloomDay.end());    
    int high = *max_element(bloomDay.begin(),bloomDay.end());    
    
        int ans = -1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(func(bloomDay,mid,k) >= m)
            {
                ans = mid;
                high = mid-1;
            }
            
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};