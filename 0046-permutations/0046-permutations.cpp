class Solution {
public:
    
    void permut(vector<int>& nums,int pos,vector<vector<int>>& ans)
    {
       if(pos >= nums.size())
       {
           ans.push_back(nums);
       }
        
        for(int i=pos;i<nums.size();i++)
        {
            swap(nums[i],nums[pos]);
            permut(nums,pos+1,ans);
            swap(nums[i],nums[pos]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        
        permut(nums,0,ans);
        
        return ans;
    }
};