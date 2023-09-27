class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int low,high,cnt=0,res=0;
        
        low = 0;
        high = nums.size()-1;
        
        while(low <= high)
        {
            long long mid = (low + high)/2;
            
            if(nums[mid] < 0)
            {
                cnt = cnt + (mid-low+1);
                low = mid+1;
            }
            
            else 
            {
                high = mid-1;
            }
        }
        
        low = 0;
        high = nums.size()-1;
        
        while(low <= high)
        {
            long long mid = (low + high)/2;
            
            if(nums[mid] > 0)
            {
                res = res + (high-mid+1);
                high = mid-1;
            }
            
            else
            {
                low = mid+1;
            }
        }
        
        return max(cnt,res);
    }
};