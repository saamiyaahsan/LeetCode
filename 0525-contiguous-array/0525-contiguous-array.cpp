class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = -1;
            }
        }
        
        map<int,int>mp;
        
        int k = 0,max_len = 0,sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            
            if(sum == k)
            {
                max_len = i+1;
            }
            
            if(mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
            
            if(mp.find(sum-k) != mp.end())
            {
                max_len = max(max_len,i-mp[sum-k]);
            }
        }
        
        return max_len;
    }
};