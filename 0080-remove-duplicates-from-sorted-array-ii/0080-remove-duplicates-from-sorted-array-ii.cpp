class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int cnt = 0,t = nums[0];
        
        vector<int>res;
        
        res.push_back(nums[0]);
         
        for(int i=1;i<nums.size();i++) 
        {
            if(nums[i] == t && cnt == 0)
            {
                res.push_back(nums[i]);
                cnt++;
            }
            
            else if(nums[i] != t)
            {
                cnt = 0;
                res.push_back(nums[i]);
                t = nums[i];
            }
        }
        
        nums.clear();
        
        for(int i=0;i<res.size();i++)
        {
            nums.push_back(res[i]);
        }
        
        return nums.size();
    }
};