class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        int ans = 0,j = 0,sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
             sum = sum + nums[i];
             mp[nums[i]]++;
            
         
            while(mp[nums[i]] > 1)
            {
                    sum = sum - nums[j];
                    mp[nums[j]]--;
                    
                    if(mp[nums[j]] == 0)
                    {
                        mp.erase(nums[j]);
                    }
                    j++;
                
            }
            
            ans = max(ans,sum);
        }
        
       return ans;
    }
};