class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        unordered_map<int,int>mp;
         
        vector<int>res;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]] == 1 && mp[nums[i]-1] == 0 && mp[nums[i]+1] == 0)
            {
                res.push_back(nums[i]);
                mp[nums[i]]--;
            }
        }
        
        return res;
    }
};