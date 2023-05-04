class Solution {
public:
    
    void helper(vector<int>& candidates,int index,int sum,int target,vector<int>res,vector<vector<int>>&ans)
    {
        if(index < 0 || index >= candidates.size() || sum > target)
        {
            return;
        }
        
        res.push_back(candidates[index]);
        
        sum = sum + candidates[index];
        
        if(sum == target)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=index;i<candidates.size();i++)
        {
            helper(candidates,i,sum,target,res,ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int sum = 0;
        
        vector<int>res;
        vector<vector<int>>ans;
        
        for(int i=0;i<candidates.size();i++)
        {
             helper(candidates,i,sum,target,res,ans);      
        }
      
        
        return ans;
    }
};