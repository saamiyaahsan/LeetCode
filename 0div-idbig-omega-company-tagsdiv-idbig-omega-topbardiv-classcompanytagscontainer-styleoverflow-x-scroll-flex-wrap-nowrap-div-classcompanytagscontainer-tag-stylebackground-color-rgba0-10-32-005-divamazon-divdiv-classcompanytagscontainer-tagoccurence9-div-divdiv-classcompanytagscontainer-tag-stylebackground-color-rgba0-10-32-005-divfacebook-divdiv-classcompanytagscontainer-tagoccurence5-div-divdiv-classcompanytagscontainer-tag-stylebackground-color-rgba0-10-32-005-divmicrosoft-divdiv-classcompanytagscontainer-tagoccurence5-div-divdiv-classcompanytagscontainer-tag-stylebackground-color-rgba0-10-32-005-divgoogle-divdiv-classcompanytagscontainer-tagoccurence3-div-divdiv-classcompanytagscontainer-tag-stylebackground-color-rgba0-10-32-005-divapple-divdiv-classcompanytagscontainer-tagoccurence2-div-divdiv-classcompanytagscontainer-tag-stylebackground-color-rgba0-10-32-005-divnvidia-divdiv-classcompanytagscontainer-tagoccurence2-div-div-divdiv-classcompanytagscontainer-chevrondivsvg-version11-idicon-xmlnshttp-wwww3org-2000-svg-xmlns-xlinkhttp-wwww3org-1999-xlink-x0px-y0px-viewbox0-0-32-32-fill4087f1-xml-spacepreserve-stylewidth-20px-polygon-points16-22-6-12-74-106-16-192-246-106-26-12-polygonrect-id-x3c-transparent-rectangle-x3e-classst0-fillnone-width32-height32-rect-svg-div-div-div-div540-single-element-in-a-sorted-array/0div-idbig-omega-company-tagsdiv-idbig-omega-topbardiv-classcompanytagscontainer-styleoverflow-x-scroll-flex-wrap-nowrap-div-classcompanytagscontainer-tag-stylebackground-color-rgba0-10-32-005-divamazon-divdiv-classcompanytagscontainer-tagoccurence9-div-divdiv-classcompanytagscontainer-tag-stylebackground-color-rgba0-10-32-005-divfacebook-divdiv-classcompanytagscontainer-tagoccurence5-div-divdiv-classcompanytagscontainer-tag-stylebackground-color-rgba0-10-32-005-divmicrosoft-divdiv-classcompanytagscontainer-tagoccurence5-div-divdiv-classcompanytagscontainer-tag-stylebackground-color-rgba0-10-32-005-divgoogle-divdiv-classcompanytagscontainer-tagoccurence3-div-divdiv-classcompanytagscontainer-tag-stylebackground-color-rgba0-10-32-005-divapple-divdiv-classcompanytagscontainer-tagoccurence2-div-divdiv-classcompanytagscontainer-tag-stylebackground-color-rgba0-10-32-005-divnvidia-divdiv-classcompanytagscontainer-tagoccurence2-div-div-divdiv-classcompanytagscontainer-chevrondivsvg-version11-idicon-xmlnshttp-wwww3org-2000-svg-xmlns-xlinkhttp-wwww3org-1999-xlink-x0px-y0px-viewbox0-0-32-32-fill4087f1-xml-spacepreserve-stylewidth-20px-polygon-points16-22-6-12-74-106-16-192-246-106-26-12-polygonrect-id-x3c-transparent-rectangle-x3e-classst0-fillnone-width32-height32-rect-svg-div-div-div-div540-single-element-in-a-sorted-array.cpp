class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        int low,high;
        
        low = 0;
        high = nums.size()-1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(nums[mid] != nums[mid+1] && mid == 0)
            {
                return nums[mid];
            }
            
            if(nums[mid] != nums[mid-1] && mid == nums.size()-1)
            {
                return nums[mid];
            }
            
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }
            
            if(nums[mid] == nums[mid-1] && mid % 2 == 0 || nums[mid] == nums[mid+1] && mid % 2 == 1)
            {
                high = mid-1;
            }
            
            else
            {
                low = mid+1;
            }
        }
        
        return -1;
    }
};