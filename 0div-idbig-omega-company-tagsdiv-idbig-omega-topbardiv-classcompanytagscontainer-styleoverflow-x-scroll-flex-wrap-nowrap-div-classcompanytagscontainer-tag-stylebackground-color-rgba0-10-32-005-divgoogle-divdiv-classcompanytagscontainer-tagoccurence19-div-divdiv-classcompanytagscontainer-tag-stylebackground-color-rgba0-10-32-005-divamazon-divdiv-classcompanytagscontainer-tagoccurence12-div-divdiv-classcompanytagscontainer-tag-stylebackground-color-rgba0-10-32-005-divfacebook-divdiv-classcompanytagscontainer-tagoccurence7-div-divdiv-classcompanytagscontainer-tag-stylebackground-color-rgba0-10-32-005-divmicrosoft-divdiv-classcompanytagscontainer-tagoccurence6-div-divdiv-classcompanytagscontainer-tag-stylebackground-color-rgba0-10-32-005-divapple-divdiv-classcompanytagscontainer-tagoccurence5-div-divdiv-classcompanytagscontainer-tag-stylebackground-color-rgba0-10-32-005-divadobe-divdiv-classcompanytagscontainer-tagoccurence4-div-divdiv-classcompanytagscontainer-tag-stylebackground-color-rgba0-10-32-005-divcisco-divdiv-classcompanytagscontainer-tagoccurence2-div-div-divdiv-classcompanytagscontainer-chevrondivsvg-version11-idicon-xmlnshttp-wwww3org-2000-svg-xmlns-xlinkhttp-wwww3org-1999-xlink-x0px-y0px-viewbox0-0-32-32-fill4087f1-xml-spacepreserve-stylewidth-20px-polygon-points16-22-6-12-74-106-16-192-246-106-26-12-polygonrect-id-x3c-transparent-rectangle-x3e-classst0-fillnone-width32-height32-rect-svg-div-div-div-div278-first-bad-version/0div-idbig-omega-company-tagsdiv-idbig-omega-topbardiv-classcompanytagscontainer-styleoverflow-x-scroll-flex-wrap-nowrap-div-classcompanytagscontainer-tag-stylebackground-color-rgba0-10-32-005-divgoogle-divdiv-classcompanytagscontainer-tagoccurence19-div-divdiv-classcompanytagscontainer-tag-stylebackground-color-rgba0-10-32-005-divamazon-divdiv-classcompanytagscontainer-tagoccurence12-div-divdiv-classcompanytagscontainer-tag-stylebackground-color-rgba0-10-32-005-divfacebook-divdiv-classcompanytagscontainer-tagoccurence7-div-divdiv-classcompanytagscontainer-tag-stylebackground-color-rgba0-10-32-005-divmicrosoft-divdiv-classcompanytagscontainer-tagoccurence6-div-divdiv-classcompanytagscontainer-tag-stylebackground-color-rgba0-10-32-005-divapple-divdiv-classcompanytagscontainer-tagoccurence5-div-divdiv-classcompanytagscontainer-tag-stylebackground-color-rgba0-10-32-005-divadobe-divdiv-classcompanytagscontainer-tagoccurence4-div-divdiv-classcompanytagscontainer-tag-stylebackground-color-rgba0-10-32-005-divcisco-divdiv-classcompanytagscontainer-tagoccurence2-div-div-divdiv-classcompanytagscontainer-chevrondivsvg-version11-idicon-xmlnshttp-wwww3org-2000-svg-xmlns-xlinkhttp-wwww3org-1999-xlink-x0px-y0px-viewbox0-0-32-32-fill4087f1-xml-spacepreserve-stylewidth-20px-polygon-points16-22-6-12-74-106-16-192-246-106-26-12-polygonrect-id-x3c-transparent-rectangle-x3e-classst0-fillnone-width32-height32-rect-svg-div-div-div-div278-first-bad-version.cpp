// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        long long low,high,ans = 0;
        
        low = 1,high = n;
        
        while(low <= high)
        {
            long long mid = (low + high)/2;
            
            if(isBadVersion(mid) == true)
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