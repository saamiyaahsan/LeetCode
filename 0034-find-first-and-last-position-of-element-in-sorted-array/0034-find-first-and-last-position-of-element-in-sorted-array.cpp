class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      
        int leftIndex = -1,rightIndex = -1;
        
        int i,j,mid;
        
        i = 0;
        j = nums.size()-1;
        
        while(i <= j)
        {
            mid = (i + j)/2;
            
            if(target == nums[mid])
            {
                leftIndex = mid;
                j = mid-1;
            }
            
            else if(target > nums[mid])
            {
                i = mid + 1;
            }
            
            else
            {
                j = mid-1;
            }
        }
        
        i = 0;
        j = nums.size()-1;
        
        
        while(i <= j)
        {
           mid = (i+j)/2;
            
           if(target == nums[mid]) 
           {
               rightIndex = mid;
               i = mid + 1;
           }
            
            else if(target > nums[mid])
            {
                i = mid + 1;
            }
            
            else
            {
                j = mid - 1;
            }
        }
        
        vector<int>ans;
        
        ans.push_back(leftIndex);
        ans.push_back(rightIndex);
        
        return ans;
    }
};