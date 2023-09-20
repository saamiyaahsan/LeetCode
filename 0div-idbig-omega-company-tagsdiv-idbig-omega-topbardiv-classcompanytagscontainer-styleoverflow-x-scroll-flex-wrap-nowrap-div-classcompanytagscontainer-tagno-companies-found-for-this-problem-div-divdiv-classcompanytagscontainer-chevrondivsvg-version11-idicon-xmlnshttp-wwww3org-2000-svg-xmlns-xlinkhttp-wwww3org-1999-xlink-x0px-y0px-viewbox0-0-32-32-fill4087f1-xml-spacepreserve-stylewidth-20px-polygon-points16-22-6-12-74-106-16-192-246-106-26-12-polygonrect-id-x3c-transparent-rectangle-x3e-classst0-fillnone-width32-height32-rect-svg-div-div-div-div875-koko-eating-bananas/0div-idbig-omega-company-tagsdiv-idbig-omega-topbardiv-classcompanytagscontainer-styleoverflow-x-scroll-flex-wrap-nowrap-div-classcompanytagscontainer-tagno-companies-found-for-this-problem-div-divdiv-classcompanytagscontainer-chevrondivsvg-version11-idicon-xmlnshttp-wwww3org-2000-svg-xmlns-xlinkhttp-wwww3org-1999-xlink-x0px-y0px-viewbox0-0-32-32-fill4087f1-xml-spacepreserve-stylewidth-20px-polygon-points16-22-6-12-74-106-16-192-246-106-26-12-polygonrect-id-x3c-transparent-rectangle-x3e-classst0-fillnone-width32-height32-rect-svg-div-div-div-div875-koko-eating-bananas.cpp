class Solution {
public:
    
    long long helper(vector<int>& piles,int k)
    {
        long long ans = 0;
        
        for(int i=0;i<piles.size();i++)
        {
            ans = ans + ceil((double)(piles[i])/(double)(k));
        }
        
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low,high,ans = 0;
        
        high = 0;
        
        for(int i=0;i<piles.size();i++)
        {
            high = max(high,piles[i]);
        }
        
        low = 1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(helper(piles,mid) <= h)
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