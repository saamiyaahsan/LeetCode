class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        int ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            ans = max(ans,mp[nums[i]]);
        }
        
        vector<vector<int>>res(ans);
        
        for(auto it : mp)
        {
            for(int i=0;i<it.second;i++)
            {
                res[i].push_back(it.first);
            }
        }
        
        return res;
    }
};