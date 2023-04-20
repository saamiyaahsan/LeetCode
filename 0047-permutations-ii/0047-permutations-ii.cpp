class Solution {
public:
    
    void permut(vector<int>& nums,int pos,set<vector<int>>& ans) 
    {
        if(pos >= nums.size())
        {
            ans.insert(nums);
            return;
        }
        
        for(int i=pos;i<nums.size();i++)
        {
            swap(nums[i],nums[pos]);
            permut(nums,pos+1,ans);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>ans;
        vector<vector<int>>res;
        
        permut(nums,0,ans);
        
        for(auto it : ans)
        {
            res.push_back(it);
        }
        
        return res;
    }
};