class Solution {
public:
    
    void helper(vector<int>& nums,int index,vector<int>res,set<vector<int>>& ans)
    {
        if(index >= nums.size())
        {
            return;
        }
        
        res.push_back(nums[index]);
        ans.insert(res);
        
        for(int i=index+1;i<nums.size();i++)
        {
            helper(nums,i,res,ans);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<int>res;
        set<vector<int>>ans;
        
        ans.insert({});
        
        for(int i=0;i<nums.size();i++)
        {
            helper(nums,i,res,ans);
        }
        
        vector<vector<int>>RES;
        
        RES.push_back({});
        
        for(auto it : ans)
        {
            RES.push_back(it);
        }
        
        return RES;
    }
};