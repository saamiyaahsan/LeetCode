class Solution {
public:
    
    int helper(vector<int>& nums,int divisor)
    {
        int res = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            res = res + ceil((double)nums[i]/(double)divisor);
        }
        
        return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int maxi = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            maxi = max(maxi,nums[i]);
        }
        
        int low = 1,high = maxi,ans=0;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(helper(nums,mid) <= threshold)
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