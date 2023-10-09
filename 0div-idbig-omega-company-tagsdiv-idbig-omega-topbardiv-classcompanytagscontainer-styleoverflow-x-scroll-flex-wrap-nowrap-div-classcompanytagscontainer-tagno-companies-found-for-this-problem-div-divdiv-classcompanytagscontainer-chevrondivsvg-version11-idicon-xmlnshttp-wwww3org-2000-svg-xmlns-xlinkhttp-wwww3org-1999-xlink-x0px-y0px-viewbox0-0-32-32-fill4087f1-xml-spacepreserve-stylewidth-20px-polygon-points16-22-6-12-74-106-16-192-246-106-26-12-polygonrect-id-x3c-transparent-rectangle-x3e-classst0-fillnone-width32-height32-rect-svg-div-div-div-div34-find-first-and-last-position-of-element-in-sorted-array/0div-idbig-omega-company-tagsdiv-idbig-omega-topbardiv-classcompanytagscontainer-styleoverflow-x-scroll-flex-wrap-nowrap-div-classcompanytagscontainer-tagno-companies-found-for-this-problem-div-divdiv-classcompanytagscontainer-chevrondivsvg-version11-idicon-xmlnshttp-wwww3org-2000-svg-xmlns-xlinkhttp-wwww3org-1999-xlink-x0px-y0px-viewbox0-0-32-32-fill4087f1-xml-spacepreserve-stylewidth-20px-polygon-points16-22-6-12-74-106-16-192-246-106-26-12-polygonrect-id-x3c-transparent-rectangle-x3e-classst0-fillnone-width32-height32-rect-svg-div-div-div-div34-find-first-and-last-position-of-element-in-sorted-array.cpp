class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>res;
        
        int l,r,low,high;
        
        l = -1;
        r = -1;
        
        low = 0;
        high = nums.size()-1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(nums[mid] == target)
            {
                l = mid;
                high = mid-1;
            }
            
            else if(nums[mid] < target)
            {
                low = mid + 1;
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
            int mid = (low + high)/2;
            
            if(nums[mid] == target)
            {
                r = mid;
                low = mid + 1;
            }
            
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            
            else
            {
                high = mid - 1;
            }
        }
        
        res.push_back(l);
        res.push_back(r);
        
        return res;
    }
};