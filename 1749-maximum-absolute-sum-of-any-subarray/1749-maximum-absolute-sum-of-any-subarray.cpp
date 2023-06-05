class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int sum = 0,ans = INT_MIN,res=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            ans = max(ans,sum);
            
            if(sum < 0)
            {
                sum = 0;
            }
        }
        
        sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            res = min(res,sum);
            
            if(sum > 0)
            {
                sum = 0;
            }
        }
        
        res = abs(res);
        
        ans = max(ans,res);
        
        return ans;
    }
};