class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int i,j,mid,ans;
        
        i = 0;
        j = nums.size();
        mid = (i+j)/2;
        
        if(target > nums[j-1])
        {
            return j;
        }
        
        while(i <= j)
        {
            mid = (i+j)/2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            
            else if(nums[mid] > target)
            {
                j = mid-1;
            }
            
            else
            {
                i = mid+1;
            }
        }
        
        return i;
    }
};