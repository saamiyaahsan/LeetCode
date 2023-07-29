class Solution {
public:
    
    int helper(vector<int>& nums,int K)
    {
        map<int,int>mp;
        
        int ans = 0, j = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
            while(mp.size() > K)
            {
                mp[nums[j]]--;
                
                if(mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
                
                j++;
            }
            
            ans = ans + (i-j+1);
        }       
        
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
      int ans;
        
      ans = helper(nums,k) - helper(nums,k-1);
        
        return ans;
    }
};