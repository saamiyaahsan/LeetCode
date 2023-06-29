class Solution {
public:
    
    void helper(int k,int n,int index,vector<vector<int>>& ans,vector<int>res)
    {
        if(k == 0 && n == 0)
        {
            ans.push_back(res);
            return;
        }
        
        if(k < 0 || n < 0)
        {
            return;
        }
        for(int i=index;i<=9;i++)
        {
            res.push_back(i);
            helper(k-1,n-i,i+1,ans,res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>res;
        
        helper(k,n,1,ans,res);
        return ans;
    }
};