class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0,j = 0,sum = 0,ans=INT_MAX;
        
        while(j < nums.size())
        {
            sum = sum + nums[j];
            
            while(sum >= target)
            {
                ans = min(ans,j-i+1);
                sum = sum - nums[i];
                i++;
            }
            
            j++;
        }
        
        if(ans < 0 || ans == INT_MAX)
        {
            return 0;
        }
        
        return ans;
    }
    
};