class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        map<int,int>mp;
        
        vector<int>res;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto it : mp)
        {
            if(it.second == 2)
            {
                res.push_back(it.first);
            }
        }
        
        return res;
    }
};