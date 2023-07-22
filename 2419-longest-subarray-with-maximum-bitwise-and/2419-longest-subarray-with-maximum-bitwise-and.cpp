class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       
        int p=0,c=1,ans=1;
        
        for(int i=0;i<nums.size();i++)
        {
            p = max(p,nums[i]);
        }
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == p && nums[i] == nums[i+1])
            {
                c++;
            }
            
            else
            {
                c=1;
            }
            
            ans = max(ans,c);
        }
        
        return ans;
    }
};