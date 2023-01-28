class Solution {
public:
    int shareCandies(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        
        int ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]--;
            
            if(mp[nums[i]] == 0)
            {
                mp.erase(nums[i]);
            }
        }
        
        int p;
        
        p = mp.size();
        
        ans = max(ans,p);
        
        for(int i=k;i<nums.size();i++)
        {
            mp[nums[i-k]]++;
            mp[nums[i]]--;
            
            if(mp[nums[i]] == 0)
            {
                mp.erase(nums[i]);
            }
            
            p = mp.size();
            
            ans = max(ans,p);
        }
        
        return ans;
    }
};