class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        int sum = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < 0 && k > 0)
            {
                nums[i] = (-1*nums[i]);
                k--;
            }
            
            else
            {
                break;
            }
        }
        
        sort(nums.begin(),nums.end());
        
        if(k % 2 == 1)
        {
            nums[0] = (-1*nums[0]);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
        }
        
        return sum;
    }
};