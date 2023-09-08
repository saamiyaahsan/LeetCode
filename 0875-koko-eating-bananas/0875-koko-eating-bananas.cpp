class Solution {
public:
    
    long long countminSpeed(vector<int>& piles,int k)
    {
        long long ans = 0;
        
        for(int i=0;i<piles.size();i++)
        {
            ans = ans + ceil((double)(piles[i])/(double)(k));
        }
        
        return ans;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
       
        int maxi = 0;
        
        for(int i=0;i<piles.size();i++)
        {
            maxi = max(maxi,piles[i]);
        }
        
        int low = 1,high = maxi,ans = 0;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(countminSpeed(piles,mid) <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};