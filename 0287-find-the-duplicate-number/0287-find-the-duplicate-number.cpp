class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        
        int p = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == p)
            {
                return p;
            }
            
            else
            {
                p = nums[i];
            }
        }
        
        return -1;
    }
};