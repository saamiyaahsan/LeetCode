class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        
        vector<int>res;
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
        }
        
        int p = mp.size();
        
        res.push_back(p);
        
        for(int i=k;i<nums.size();i++)
        {
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            
            if(mp[nums[i-k]] == 0)
            {
                mp.erase(nums[i-k]);
            }
            
            p = mp.size();
            res.push_back(mp.size());
        }
        
        return res;
    }
};