class Solution {
public:
    int mySqrt(int x) {
       
        int low,high,ans=-1;
         
        low = 0;
        high = x;
        
        if(x == 0)
        {
            return 0;
        }
        
        if(x == 1)
        {
            return 1;
        }
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(mid <= x/mid)
            {
                ans = mid;
                low = mid+1;
            }
            
            else
            {
                high = mid-1;
            }
            
            
        }
        
        return ans;
    }
};