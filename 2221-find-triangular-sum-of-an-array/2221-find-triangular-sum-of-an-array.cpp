class Solution {
public:
    
    void helper(vector<int>& nums)
    {
        vector<int>res;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            int p = (nums[i] + nums[i+1]) % 10;
            res.push_back(p);
        }
        
        nums.clear();
        
        nums = res;
    }
    int triangularSum(vector<int>& nums) {
        
        while(nums.size() != 1)
        {
           helper(nums);        
        }
        
        return nums[0];
    }
};