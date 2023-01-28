class Solution {
public:
    
    int helper(vector<int>& nums,int x)
    {
        int ans = 0,j = -1; 
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
            while(mp.size() > x)
            {
                j++;
                
                mp[nums[j]]--;
                
                if(mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
            }
            
            ans = ans + (i-j);
        }
        
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return helper(nums,k) - helper(nums,k-1);
        
    }
};