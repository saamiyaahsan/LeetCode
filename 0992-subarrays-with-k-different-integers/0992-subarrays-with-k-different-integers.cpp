class Solution {
public:
    
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        
        int cnt = 0,j = -1,res = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
            while(mp.size() > k)
            {
                j++;
                if(--mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
            }
            
            cnt = cnt + (i-j);
        }
        
          j = -1;
          
           mp.clear();
        
           for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            
            while(mp.size() > k-1)
            {
                j++;
                if(--mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
            }
            
            res = res + (i-j);
        }
        
        
        return cnt-res;
        
    }
};