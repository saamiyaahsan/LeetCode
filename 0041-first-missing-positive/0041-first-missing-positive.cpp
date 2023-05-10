class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int b = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == b)
            {
                b++;
            }
            
            else if(nums[i] > b)
            {
                return b;
            }
            
            else
            {
                continue;
            }
        }
        
        return b;
    }
};