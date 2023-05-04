class Solution {
public:
    
    void helper(int n,int k,vector<int>res,set<vector<int>>& ans,int cnt,int num) 
    {
        if(cnt > k || num > n)
        {
            return;
        }
        
        res.push_back(num);
        cnt++;
        
        if(cnt == k)
        {
            sort(res.begin(),res.end());
            ans.insert(res);
            return;
        }
        
        for(int i=num+1;i<=n;i++)
        {
            helper(n,k,res,ans,cnt,i);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        int cnt = 0,num = 1;
        vector<int>res;
        set<vector<int>>ans;
        
        for(int i=1;i<=n;i++)
        {
            helper(n,k,res,ans,cnt,i);
        }
        
        vector<vector<int>>RES;
        
        for(auto it : ans)
        {
            RES.push_back(it);
        }
        
        return RES;
    }
};