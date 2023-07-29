class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int j=0,ans=0,cntofZero=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                cntofZero++;
            }
            
            while(cntofZero > 1)
            {
                if(nums[j] == 0)
                {
                    cntofZero--;
                }
                
                j++;
            }
            
            ans = max(ans,i-j);
        }
        
        return ans;
    }
};