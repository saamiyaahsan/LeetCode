class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>res;
        
        if(nums.empty() == true)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        int i=0,j=nums.size()-1,ans = -1;
        
        while(i <= j)
        {
            int mid = (i+j)/2;
            
            if(nums[mid] == target)
            {
                ans = mid;
                j = mid-1;
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
        
        res.push_back(ans);
        
        ans = -1;
        
        i = 0;
        j = nums.size()-1;
        
        while(i <= j)
        {
            int mid = (i+j)/2;
            
            if(nums[mid] == target)
            {
                ans = mid;
                i = mid+1;
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
        
        res.push_back(ans);
        
        return res;
    }
};