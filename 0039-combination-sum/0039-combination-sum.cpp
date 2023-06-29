class Solution {
public:
    
    void helper(vector<int>& candidates,vector<vector<int>>& ans,vector<int>res,int pos,int target,int sum)
    {
        if(pos < 0 || pos >= candidates.size() || sum > target)
        {
            return;
        }
        
        res.push_back(candidates[pos]);
        sum = sum + candidates[pos];
        
        if(sum == target)
        {
            ans.push_back(res);
            return;
        }
        
        for(int i=pos;i<candidates.size();i++)
        {
            helper(candidates,ans,res,i,target,sum);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>res;
        
        int sum = 0;
        
        for(int i=0;i<candidates.size();i++)
        {
            sum = 0;
            helper(candidates,ans,res,i,target,0);
        }
        
        return ans;
    }
};