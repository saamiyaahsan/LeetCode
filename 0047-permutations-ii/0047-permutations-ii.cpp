class Solution {
public:
    
    void permut(set<vector<int>>& ans,int pos,vector<int>& nums)
    {
        if(pos >= nums.size())
        {
            ans.insert(nums);
        }
        
        for(int i=pos;i<nums.size();i++)
        {
            swap(nums[i],nums[pos]);
            permut(ans,pos+1,nums);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>ans;
        
        permut(ans,0,nums);
        
           vector<vector<int>>res(ans.begin(),ans.end());
        
        return res;
    }
};