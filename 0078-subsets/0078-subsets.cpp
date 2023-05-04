class Solution {
public:
    
    void helper(vector<int>& nums,int index,vector<int>res,vector<vector<int>>& ans)
    {
        if(index >= nums.size())
        {
            return;
        }
        
        res.push_back(nums[index]);
        ans.push_back(res);
        
        for(int i=index+1;i<nums.size();i++)
        {
            helper(nums,i,res,ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       
        vector<int>res;
        vector<vector<int>>ans;
        
        ans.push_back({});
        
        for(int i=0;i<nums.size();i++)
        {
            helper(nums,i,res,ans);
        }
        
        return ans;
    }
};