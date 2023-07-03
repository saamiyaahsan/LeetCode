class Solution {
public:
    
    long long func(vector<int>& piles,int cnt)
    {
        long long total_hrs = 0;
        
        for(int i=0;i<piles.size();i++)
        {
            total_hrs = total_hrs + ceil((double)(piles[i])/(double)(cnt));
        }
        
        return total_hrs;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
     
     int maxi = INT_MIN;   
        
     for(int i=0;i<piles.size();i++)   
     {
         maxi = max(maxi,piles[i]);
     }
       
     int low = 1 , high = maxi,ans=0;   
        
     while(low <= high)   
     {
        int mid = (low + high)/2;
         
        if(func(piles,mid) <= h)
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